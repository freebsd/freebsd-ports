--- ./sources/alloc.c.orig	Tue Dec 14 13:06:31 1999
+++ ./sources/alloc.c	Tue Aug 16 23:59:29 2005
@@ -60,7 +60,7 @@
     ++noOfElementsInBlock;
     ++freeElement;
 
-    if (noOfElementsInBlock > maxElementsInBlock) 
+    if (noOfElementsInBlock > maxElementsInBlock)
     {
 	if (noOfBlocksSinceIncrement > 100) 	// dynamic size extension
 	{
@@ -71,7 +71,7 @@
 	MemoryBlock* newBlock = ::new MemoryBlock;
 	if (newBlock == 0) allocationError();
 
-	newBlock->space = ::new T[maxElementsInBlock];  
+	newBlock->space = ::new T[maxElementsInBlock];
 	if (newBlock->space == 0) allocationError();
 
 	newBlock->next = lastBlock;
@@ -97,19 +97,19 @@
 //-------------------------------------------------------------------------
 
 template<class T> Allocator<T>:: ~Allocator()
-{ 
-    MemoryBlock* toDel;
+{
+    typename StaticAllocator<T>::MemoryBlock* toDel;
 
-    while(lastBlock)
+    while(this->lastBlock)
     {
-	toDel = lastBlock;
-	lastBlock = lastBlock->next;
+	toDel = this->lastBlock;
+	this->lastBlock = this->lastBlock->next;
 	delete [] toDel->space;
 	delete toDel;
     }
 
     int i;
-    FORALL(returnedElements,i) returnedElements[i] = 0;
+    FORALL(this->returnedElements,i) this->returnedElements[i] = 0;
 }
 //-------------------------------------------------------------------------
 
@@ -118,11 +118,11 @@
 {
     T* elem;
 
-    if (returnedElements.h == 0) elem = getFromBlock();
-    else 
-    { 
-	elem = returnedElements.pop(); 
-	elem->reset(); 
+    if (this->returnedElements.h == 0) elem = this->getFromBlock();
+    else
+    {
+	elem = this->returnedElements.pop();
+	elem->reset();
     }
     return elem;
 }
