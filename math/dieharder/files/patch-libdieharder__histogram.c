--- libdieharder/histogram.c.orig	2009-12-27 13:37:57.000000000 -0500
+++ libdieharder/histogram.c	2009-12-27 14:31:11.000000000 -0500
@@ -95,6 +95,7 @@
  for(i=0;i<nbins;i++) printf("%4.1f|",(i+1)*binscale);
  printf("\n");
  printf("#==================================================================\n");
+ free(bin);
 
 }
 
