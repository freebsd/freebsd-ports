--- conversion/minctoecat/machine_indep.c.orig	2012-07-20 17:16:13.000000000 +0200
+++ conversion/minctoecat/machine_indep.c	2012-07-20 17:17:48.000000000 +0200
@@ -84,7 +84,7 @@
 	bufr[1] =  ret >>16;
 }
 #else  /* BIG ENDIAN : sun hp sgi*/
-ftovaxf(orig,number)
+void ftovaxf(orig,number)
   unsigned short number[2];
   float orig;
 {
