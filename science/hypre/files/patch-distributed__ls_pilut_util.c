--- distributed_ls/pilut/util.c.orig	2021-11-07 12:06:10 UTC
+++ distributed_ls/pilut/util.c
@@ -28,15 +28,15 @@ HYPRE_Int hypre_ExtractMinLR( hypre_PilutSolverGlobals
   HYPRE_Int i, j=0 ;
 
   for (i=1; i<lastlr; i++) {
-    if (lr[i] < lr[j])
+    if (hypre_lr[i] < hypre_lr[j])
       j = i;
   }
-  i = lr[j];
+  i = hypre_lr[j];
 
   /* Remove it */
   lastlr-- ;
   if (j < lastlr) 
-    lr[j] = lr[lastlr];
+    hypre_lr[j] = hypre_lr[lastlr];
 
   return i;
 }
