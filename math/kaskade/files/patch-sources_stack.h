--- ./sources/stack.h.orig	Fri Dec 10 15:20:50 1999
+++ ./sources/stack.h	Tue Aug 16 22:01:00 2005
@@ -30,7 +30,7 @@
 
     virtual T Top()  const;
 
-    int empty() const { return h < l; }
+    int empty() const { return this->h < this->l; }
 
     virtual void resize(int newTop);
     virtual void resize(int newl, int newTop);
