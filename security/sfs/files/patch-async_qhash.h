--- async/qhash.h.orig	Mon Oct 11 16:43:34 2004
+++ async/qhash.h	Mon Oct 11 16:39:35 2004
@@ -166,7 +166,7 @@
 
 public:
   bhash () {}
-  void clear () { deleteall (); }
+  void clear () { this->deleteall (); }
   ~bhash () { clear (); }
 
   bool insert (const K &k) {
