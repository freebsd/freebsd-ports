--- math++/nodes.h.orig	Fri Aug 13 12:59:11 2004
+++ math++/nodes.h	Fri Aug 13 12:59:31 2004
@@ -130,7 +130,7 @@
     TNode<T> *get() const { return FCurrent; }
 
     TNodeIterator<T>& operator++() { increment(); return *this; }
-    TNodeIterator<T>& operator--() { declrement(); return *this; }
+    TNodeIterator<T>& operator--() { decrement(); return *this; }
 };
 
 template<typename T>
