#define NULL 0


typedef struct node 
{
 int data;
 struct node *prev;
 struct node *next;
}node;




//for allocating memory to new node
node * newnode(node *l,int val)
{

 l=(node *) malloc (sizeof(node));
 l->data=val;
 l->next=NULL;
 l->prev=NULL;
 return l;
}


//for inserting new node at end
node * insertend(node *l,int val)
{
 if(l==NULL)
   return newnode(l,val);
 else
 {
  l->next=insertend(l->next,val);
  l->next->prev=l;
  return l;
 } 
}


//for inserting new node at start
node * insertfront(node *l,int val)
{
 node *temp=newnode(NULL,val);
 l->prev=temp;
 temp->next=l;
 return temp;
}


//for deleting node from end
node * deleteend(node *l)
{
 if(l->next==NULL)
  {
   free(l); 
   return NULL;
  }  
 else
  {
   l->next=deleteend(l->next);
   return l;
  }
}


//for deleting node from front
node * deletefront(node *l)
{
  node *temp=l->next;
  free(l);
  temp->prev=NULL;
  return temp;
}


//returns no of nodes in list
int length(node *l)
{
 if(l==NULL)
   return 0;
 else 
    return (1+length(l->next));
}


void display(node *l)
{
  if(l==NULL)
    return ;
  else
  {
   printf("%d\t",l->data);
   display(l->next);
  }
}

//creates first node of list i.e. creating list
node * createlist(node *l,int val)
{
 return insertend(l,val);
}




