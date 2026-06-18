#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if(amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance\n";
    }

    double getBalance()
    {
        return balance;
    }

    virtual void calculateInterest()
    {
        cout << "No Interest Calculation\n";
    }

    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolderName;
        cout << "\nBalance : " << balance << endl;
    }

    virtual ~BankAccount(){}
};


// Savings Account
class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo,string name,double bal,double rate)
    : BankAccount(accNo,name,bal)
    {
        interestRate = rate;
    }

    void calculateInterest()
    {
        double interest = balance * interestRate / 100;
        cout << "\nSavings Interest = " << interest << endl;
    }
};


// Checking Account
class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo,string name,double bal,double limit)
    : BankAccount(accNo,name,bal)
    {
        overdraftLimit = limit;
    }

    void checkOverdraft()
    {
        cout << "\nOverdraft Limit = "
             << overdraftLimit << endl;
    }
};


// Fixed Deposit Account
class FixedDepositAccount : public BankAccount
{
private:
    int term;

public:
    FixedDepositAccount(int accNo,string name,
                        double bal,int t)
    : BankAccount(accNo,name,bal)
    {
        term = t;
    }

    void calculateInterest()
    {
        double interest =
            balance * 0.08 * term / 12;

        cout << "\nFD Interest = "
             << interest << endl;
    }
};


int main()
{
    int choice;

    SavingsAccount sa(101,"Rahul",50000,5);
    CheckingAccount ca(102,"Priya",30000,10000);
    FixedDepositAccount fd(103,"Amit",100000,12);

    do
    {
        cout << "\n===== BANKING SYSTEM =====";
        cout << "\n1. Savings Account";
        cout << "\n2. Checking Account";
        cout << "\n3. Fixed Deposit Account";
        cout << "\n4. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                sa.displayAccountInfo();
                sa.calculateInterest();
                break;

            case 2:
                ca.displayAccountInfo();
                ca.checkOverdraft();
                break;

            case 3:
                fd.displayAccountInfo();
                fd.calculateInterest();
                break;

            case 4:
                cout << "\nThank You";
                break;

            default:
                cout << "\nInvalid Choice";
        }

    }while(choice != 4);

    return 0;
}