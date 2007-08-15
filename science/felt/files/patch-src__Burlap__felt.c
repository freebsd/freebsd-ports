--- src/Burlap/felt.c.orig	Tue Feb 22 07:44:30 2000
+++ src/Burlap/felt.c	Sat Aug  4 22:27:50 2007
@@ -1780,7 +1780,7 @@
     D_Type    (d) = T_Problem;
     D_Temp    (d) = F_False;
     D_Trapped (d) = F_False;
-    D_Problem (d) = &problem;
+    d->u.ptr      = &problem;
 
 
     s = add_literal (&var_st, "analysis", GlblOp);
@@ -1789,7 +1789,7 @@
     D_Type     (d) = T_Analysis;
     D_Temp     (d) = F_False;
     D_Trapped  (d) = F_False;
-    D_Analysis (d) = &analysis;
+    d->u.ptr       = &analysis;
 
     return 0;
 }
