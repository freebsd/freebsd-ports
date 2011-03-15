--- ./libdieharder/rgb_operm.c.orig	2011-03-15 06:04:56.000000000 -0400
+++ ./libdieharder/rgb_operm.c	2011-03-15 06:09:38.000000000 -0400
@@ -231,6 +231,7 @@
  free(cexpt);
   */
  
+ free(count);
  return(0);
 
 }
