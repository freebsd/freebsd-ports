--- ./sources/stack.c.orig	Thu Oct 10 12:01:26 1996
+++ ./sources/stack.c	Tue Aug 16 23:20:18 2005
@@ -8,77 +8,77 @@
 #include "stack.h"
 
 
-template<class T> 
-Stack<T>:: Stack(int l1, int top1, int h1) 
-			   : Vector<T>(l1,top1)  { top=top1; h=h1; }
-
-template<class T>  
-Stack<T>:: Stack(int l1, int top1) 
-			   : Vector<T>(l1,top1)  { top=top1; h=l1-1; }
+template<class T>
+Stack<T>:: Stack(int l1, int top1, int h1)
+			   : Vector<T>(l1,top1)  { top=top1; this->h=h1; }
+
+template<class T>
+Stack<T>:: Stack(int l1, int top1)
+			   : Vector<T>(l1,top1)  { top=top1; this->h=l1-1; }
 
-template<class T> 
-Stack<T>:: Stack(int top1) : Vector<T>(1,top1)   { top=top1; h=0;}
+template<class T>
+Stack<T>:: Stack(int top1) : Vector<T>(1,top1)   { top=top1; this->h=0;}
 
-template<class T> 
-Stack<T>:: Stack()         : Vector<T>(DefaultSize) { top=DefaultSize; h=0;}
+template<class T>
+Stack<T>:: Stack()         : Vector<T>(DefaultSize) { top=DefaultSize; this->h=0;}
 
 
 
 template<class T> void Stack<T>:: push(const T a)
 {
-    if (h==top) extend();
-    v[++h] = a;
+    if (this->h==top) extend();
+    this->v[++this->h] = a;
 }
 
 template<class T> T Stack<T>:: pop()
 {
-    if (h < l)
+    if (this->h < this->l)
     {
-	cout << "\n*** pop tried from empty stack \n"; 
-        cout.flush(); abort();  return v[l];	// dummy to avoid compiler warnings
+	cout << "\n*** pop tried from empty stack \n";
+        cout.flush(); abort();  return this->v[this->l];	// dummy to avoid compiler warnings
     }
-    else return v[h--];
+    else return this->v[this->h--];
 }
 
 template<class T> T Stack<T>:: Top() const
 {
-    if (h < l)
+    if (this->h < this->l)
     {
-	cout << "\n*** Class Stack (Top): empty stack \n"; 
-        cout.flush(); abort();   return v[l];	// dummy to avoid compiler warnings
+	cout << "\n*** Class Stack (Top): empty stack \n";
+        cout.flush(); abort();   return this->v[this->l];	// dummy to avoid compiler warnings
     }
-    else return v[h];
+    else return this->v[this->h];
 }
 
 template<class T>  T Stack<T>:: Prev() const
 {
-    if (h <= l)
+    if (this->h <= this->l)
     {
-	cout << "\n*** Class Stack (Prev): only one element on stack \n"; 
-        cout.flush(); abort();   return v[l];	// dummy to avoid compiler warnings
+	cout << "\n*** Class Stack (Prev): only one element on stack \n";
+        cout.flush(); abort();   return this->v[this->l];	// dummy to avoid compiler warnings
     }
-    else return v[h-1];
+    else return this->v[this->h-1];
 }
 
 template<class T> void Stack<T>:: extend()
 {
-    int stackSize = top-l+1;
+    int stackSize = top - this->l + 1;
     stackSize = int(1.5*stackSize);
     if (stackSize <= 2) stackSize = 4;
-    
-    top = l+stackSize-1;
+
+    top = this->l+stackSize-1;
     T* vnew = new T[stackSize];
-    if (!vnew) 
+    if (!vnew)
     {
-	cout << "\n*** stack extension failure: l=" <<l<< " top=" <<top<< "\n";
+	cout << "\n*** stack extension failure: l=" <<this->l<< " top=" <<top<< "\n";
 	cout.flush(); abort();
     }
-    vnew -= l;
+    vnew -= this->l;
 
-    for (int i=l; i<=h; ++i) vnew[i] = v[i];
-    v = v+l;
-    delete [] v;
-    v = vnew;
+    for (int i=this->l; i<=this->h; ++i) vnew[i] = this->v[i];
+    this->v = this->v + this->l;
+    delete [] this->v;
+    this->v = vnew;
 
     if (AnnounceExtensionFlag) cout << "\n* Stack extended to " << top << "\n";
 }
@@ -86,10 +86,10 @@
 
 template<class T> void Stack<T>:: resize(int newl, int newTop)
 {
-    v += l; delete[] v;
-    allocate (newl, newTop);
+    this->v += this->l; delete[] this->v;
+    this->allocate (newl, newTop);
     top = newTop;
-    h = newl-1;
+    this->h = newl-1;
 }
 
 template<class T> void Stack<T>:: resize(int newTop) { resize (1,newTop); }
@@ -97,11 +97,11 @@
 template<class T> void Stack<T>:: resize(int newl, int newTop, int newh)
 {
     resize(newl, newTop);
-    h = newh;
+    this->h = newh;
 }
 //-------------------------------------------------------------------------
 
 template<class T> Stack<T>:: Stack(Stack<T>& /*vec*/)
 {
-    notImplemented("Stack:: copy constructor! Check function arguments");
+    this->notImplemented("Stack:: copy constructor! Check function arguments");
 }
