--- viterbi27.c.orig	Wed Dec  5 10:01:45 2001
+++ viterbi27.c	Wed Jun 29 17:33:44 2005
@@ -164,8 +164,6 @@
   struct v27 *vp = p;
 
   if(vp != NULL){
-    free(vp->metrics1);
-    free(vp->metrics2);
     free(vp->decisions);
     free(vp->alloc_blk);
   }
