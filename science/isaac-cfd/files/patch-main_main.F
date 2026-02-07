--- ./main/main.F.orig	Mon Oct 29 04:25:28 2001
+++ ./main/main.F	Tue Apr  4 22:26:34 2006
@@ -138,7 +138,7 @@
 C           =  2 for iterative, implicit unsteady
 C           =  3 for tau-ts iterative unsteady with 2nd order pseudo sub-iter 
 C
-      PARAMETER (MAXQ   =    7)
+      PARAMETER (MAXQ   =   12)
 c--   PARAMETER (MXPTS  = 50000)
 c++   PARAMETER (MXPTS  = 34000)
 c32^3 PARAMETER (MXPTS  = 46700)
