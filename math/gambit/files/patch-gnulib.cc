--- sources/math/gnulib.cc.orig	Sun Feb  9 01:57:37 2003
+++ sources/math/gnulib.cc	Sun Feb  9 01:57:55 2003
@@ -112,7 +112,7 @@
   v &= chunklimit == chunk->limit;
   _obstack_chunk* p = chunk;
   // allow lots of chances to find bottom!
-  long x = MAXLONG;
+  long x = LONG_MAX;
   while (p != 0 && x != 0) { --x; p = p->prev; }
   v &= x > 0;
   return v;
