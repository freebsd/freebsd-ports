--- viterbi29.c.orig	Wed Dec  5 10:01:45 2001
+++ viterbi29.c	Wed Jun 29 17:33:44 2005
@@ -162,8 +162,6 @@
   struct v29 *vp = p;
 
   if(vp != NULL){
-    free(vp->metrics1);
-    free(vp->metrics2);
     free(vp->decisions);
     free(vp->alloc_blk);
   }
