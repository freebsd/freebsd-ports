--- src/lib/image2/sdl_image/IMG_png.c.orig	2002-08-05 12:43:09.000000000 +0200
+++ src/lib/image2/sdl_image/IMG_png.c	2012-05-06 16:16:38.000000000 +0200
@@ -70,6 +70,7 @@
 #define MACOS
 #endif
 #include <png.h>
+#include <pngpriv.h>
 
 #define PNG_BYTES_TO_CHECK 4
 
@@ -87,7 +88,7 @@
 }
 
 /* Load a PNG type image from an SDL datasource */
-static void png_read_data(png_structp ctx, png_bytep area, png_size_t size)
+static void local_png_read_data(png_structp ctx, png_bytep area, png_size_t size)
 {
 	SDL_RWops *src;
 
@@ -138,13 +139,13 @@
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if ( setjmp(png_ptr->jmpbuf) ) {
+	if ( setjmp(png_jmpbuf(png_ptr)) ) {
 		IMG_SetError("Error reading the PNG file.");
 		goto done;
 	}
 
 	/* Set up the input control */
-	png_set_read_fn(png_ptr, src, png_read_data);
+	png_set_read_fn(png_ptr, src, local_png_read_data);
 
 	/* Read PNG header info */
 	png_read_info(png_ptr, info_ptr);
