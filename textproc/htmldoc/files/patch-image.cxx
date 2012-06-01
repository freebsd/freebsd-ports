--- htmldoc/image.cxx.orig	2006-05-31 21:00:02.000000000 +0200
+++ htmldoc/image.cxx	2012-05-06 15:44:04.000000000 +0200
@@ -56,6 +56,7 @@
 }
 
 #include <png.h>	/* Portable Network Graphics (PNG) definitions */
+#include <pngpriv.h>
 
 
 /*
@@ -1499,7 +1500,7 @@
 
   rows = NULL;
 
-  if (setjmp(pp->jmpbuf)) 
+  if (setjmp(png_jmpbuf(pp))) 
   {
     progress_error(HD_ERROR_BAD_FORMAT, "PNG file contains errors!");
 
