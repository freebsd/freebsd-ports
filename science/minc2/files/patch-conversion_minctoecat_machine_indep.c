--- conversion/minctoecat/machine_indep.c.orig	2007-03-29 07:08:46.000000000 +0200
+++ conversion/minctoecat/machine_indep.c	2014-01-28 22:55:57.000000000 +0100
@@ -61,7 +61,7 @@
 }
 
 #if defined(__alpha) || defined(_WIN32) /* LITTLE_ENDIAN : alpha, intel */
-ftovaxf(f, bufr)
+void ftovaxf(f, bufr)
 float f;
 unsigned short *bufr;
 {
@@ -84,7 +84,7 @@
 	bufr[1] =  ret >>16;
 }
 #else  /* BIG ENDIAN : sun hp sgi*/
-ftovaxf(orig,number)
+void ftovaxf(orig,number)
   unsigned short number[2];
   float orig;
 {
