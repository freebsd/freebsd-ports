--- png.c.orig	2003-06-21 15:31:51 UTC
+++ png.c
@@ -6,6 +6,7 @@
 #include <stdlib.h>
 #include "to_png.h"
 #include <png.h>
+#include <zlib.h>
 
 #define PDNCOL 256
 
@@ -36,7 +37,7 @@ FILE *fd;
 	}
 
 	/* set up error handlimg for libpng */
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		png_destroy_write_struct(&png_ptr, &info_ptr);
 		return;
 	}
