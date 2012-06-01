--- writepng.c.orig	2009-06-12 22:58:50.000000000 +0200
+++ writepng.c	2012-05-06 06:49:53.000000000 +0200
@@ -26,6 +26,7 @@
 #include <string.h>
 
 #include <png.h>
+#include <pngpriv.h>
 
 #include "writepng.h"
 
@@ -309,7 +310,7 @@
      }
      /* Set error handling.  REQUIRED if you aren't supplying your own *
       * error hadnling functions in the png_create_write_struct() call. */
-     if (setjmp(png_ptr->jmpbuf)) {
+     if (setjmp(png_jmpbuf(png_ptr))) {
 	  /* If we get here, we had a problem reading the file */
 	  fclose(fp);
 	  png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
