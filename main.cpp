#include <iostream>

using namespace std;

void set_arr(int* arr, int n)
{
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<endl;
}

void print(int* arr, int n)
{
    cout<<"The array: "<<endl;
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    cout<<endl;
}

int binary_while(int *arr, int left, int right, int key)
{
    while(right>left)
    {
        int mid= left+(right-left)/2;
        if(arr[mid]==key)
            return mid;

        if(arr[mid]>key)
            right=mid-1;
        else
            left= mid+1;
    }
    return -1;
}

int binary_rec(int *arr, int left, int right, int key)
{
    if(right>=left)
    {
        int mid= left+(right-left)/2;
        if (arr[mid]==key)
            return mid;
        else
            if(arr[mid]>key)
                return binary_rec(arr, left, mid-1, key);
        return binary_rec(arr, mid+1, right, key);
    }
    return -1;
}


int main(int argc, char *argv[])
{
    int key=0;
    int n=0;
    cout<<"Enter size of the array: ";
    cin>>n;
    int *arr= new int[n];
    set_arr(arr, n);
    print(arr, n);
    cout<<"Enter the key: ";
    cin>>key;

    //int k= binary_rec(arr, 0, n-1, key);
    int k= binary_while(arr, 0, n-1, key);
    if(k==-1)
        cout<<"Not found"<<endl;
    else
        cout<<"The number "<<key<<" is here: "<<k<<endl;

    delete [] arr;
    return 0;
}
