--- async/ihash.h.orig	Mon Oct 11 16:43:34 2004
+++ async/ihash.h	Mon Oct 11 16:39:35 2004
@@ -213,7 +213,7 @@
   const H hash;
 
 public:
-  ihash () {}
+  ihash () : eq (E ()), hash (H ()) {}
   ihash (const E &e, const H &h) : eq (e), hash (h) {}
 
   void insert (V *elm) { insert_val (elm, hash (elm->*key)); }
