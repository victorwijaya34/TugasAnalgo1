#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;
	int mp[5][5]={1,0,3,4,2,
                  3,1,0,2,4,
                  1,4,2,3,0,
				  0,3,2,1,4,
				  1,3,0,4,2};
    int wp[5][5]={4,0,1,3,2,
                  2,1,3,0,4,
                  1,2,3,4,0,
				  0,4,3,2,1,
				  3,1,4,2,0};
    
    bool ok(int q[], int col)                  
    {   int i;
        for(i=0; i<col;i++)                    
        {
           if(q[col]==q[i])
             return false;     
        }
        
        for(i=0; i<col; i++)
        {
          if( ( mp[col][q[i]]<mp[col][q[col]] )&& ( wp[q[i]][col]<wp[q[i]][i]) )
                return false;     
          if( ( wp[q[col]][i]<wp[q[col]][col] )&& ( mp[i][q[col]]<mp[i][q[i]]) )
                return false;      
        }
        return true;  
    }
  
   void backtrack(int &col){
        col--;
        if(col==-1) exit(1);
       }
       
   void print(int q[])
    {  
       int i,j;
       cout<<"Man"<<"  "<<"Woman"<<endl;
       for( i=0;i<5;i++){
    		cout<<" "<<i<<"     "<<q[i]<<endl;
		}
    }
    int main(){
      int q[5]; 
      q[0]=0;
      int c=1;
      bool from_backtrack=false;
      while(1){
        while(c<5){ 
         if(!from_backtrack) 
            q[c]=-1; 
            from_backtrack=false;
              while(q[c]<5){ 
                q[c]++;
                    while(q[c]==5)             
                     { backtrack(c);
                       q[c]++;            
                     }
                  if(ok(q, c))
                     break;                    
              }
          c++;
     }
     print(q); 
     system("pause");
     backtrack(c);
     from_backtrack=true;
    }   
}
