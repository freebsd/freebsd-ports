--- mtrxmath.c.orig	Tue Jan  9 20:44:12 2001
+++ mtrxmath.c	Tue Jan  9 20:44:00 2001
@@ -102,7 +102,7 @@
     exit(0);
   }
   if (cmdopt==INVERT) {
-    final == inverse(foo);
+    final = inverse(foo);
     show_matrix(final);
     exit(0);
   } 
