--- eval.cc.orig	2014-03-27 17:24:43.000000000 +0400
+++ eval.cc	2014-09-04 21:33:12.000000000 +0400
@@ -474,10 +474,10 @@
   void *c;
   int i;
   int argc=pexpr->n();
-  tValue v[argc];
+  std::vector<tValue> v(argc);
   tInt n[argc];
   tReal r[argc];
-  tComplex z[argc];
+  std::vector<tComplex> z(argc);
   tInt rn;
   tReal rr;
   TRACE();
