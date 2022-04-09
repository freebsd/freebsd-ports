--- ../inst/lsqlin.m.orig	2022-04-08 22:29:29.290901000 -0500
+++ ../inst/lsqlin.m	2022-04-08 22:29:41.495111000 -0500
@@ -115,7 +115,7 @@
 
   if (n_out > 2)
     ## We don't need to know if original n_out was 3 or 2.
-    n_out --;
+    n_out--;
   endif
 
   quadprog_out = cell (1, max (n_out, 1));
