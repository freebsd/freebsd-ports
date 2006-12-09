--- src/cdo.c.orig	Tue Sep 12 14:50:14 2006
+++ src/cdo.c	Mon Dec  4 17:38:55 2006
@@ -663,7 +663,7 @@
       fprintf(stderr, "FLT_EVAL_METHOD     = %d\n", FLT_EVAL_METHOD);
 #endif
 #if defined (FP_FAST_FMA)
-      fprintf(stderr, "FP_FAST_FMA         = %d\n", FP_FAST_FMA);
+      fprintf(stderr, "FP_FAST_FMA         = defined\n");
 #endif
       fprintf(stderr, "\n");
 
