--- fig2dev/dev/readpng.c.orig	2010-04-21 18:02:14.000000000 +0200
+++ fig2dev/dev/readpng.c	2012-05-05 13:20:54.000000000 +0200
@@ -16,6 +16,7 @@
 #include "fig2dev.h"
 #include "object.h"
 #include <png.h>
+#include <pngpriv.h>
 
 /* return codes:  1 : success
 		  0 : invalid file
@@ -62,7 +63,7 @@
     }
 
     /* set long jump here */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* if we get here there was a problem reading the file */
 	png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
 	return 0;
