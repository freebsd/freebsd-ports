--- ext/gd/gd.c.orig	Mon Jun 11 17:22:10 2001
+++ ext/gd/gd.c	Fri Nov 30 10:14:50 2001
@@ -335,8 +335,11 @@
 
 /* this next part is stupid ... if I knew better, I'd put them all on one row (cmv) */
 
-#ifdef HAVE_GD_GIF
-	php_info_print_table_row(2, "GIF Support", "enabled");
+#ifdef HAVE_GD_GIF_READ
+	php_info_print_table_row(2, "GIF Read Support", "enabled");
+#endif
+#ifdef(HAVE_GD_GID_CREATE)
+	php_info_print_table_row(2, "GIF Create Support", "enabled");
 #endif
 #ifdef HAVE_GD_JPG
 	php_info_print_table_row(2, "JPG Support", "enabled");
@@ -1088,7 +1091,7 @@
 			break;
 			
 		case PHP_GDIMG_TYPE_GIF:
-#ifdef HAVE_GD_GIF
+#ifdef HAVE_GD_GIF_READ
 			im = _php_image_create_from_string (data, "GIF", gdImageCreateFromGifCtx);
 #else
 			php_error(E_WARNING, "No GIF support in this PHP build");
@@ -1205,9 +1208,9 @@
    Create a new image from GIF file or URL */
 PHP_FUNCTION(imagecreatefromgif)
 {
-#ifdef HAVE_GD_GIF
+#ifdef HAVE_GD_GIF_READ
 	_php_image_create_from(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHP_GDIMG_TYPE_GIF, "GIF", gdImageCreateFromGif,gdImageCreateFromGifCtx);
-#else /* HAVE_GD_GIF */
+#else /* HAVE_GD_GIF_READ */
 	php_error(E_WARNING, "ImageCreateFromGif: No GIF support in this PHP build");
 	RETURN_FALSE;
 #endif /* HAVE_GD_GIF */
@@ -1397,14 +1400,14 @@
    Output GIF image to browser or file */
 PHP_FUNCTION(imagegif)
 {
-#ifdef HAVE_GD_GIF
+#ifdef HAVE_GD_GIF_CREATE
 #ifdef HAVE_GD_GIF_CTX
 	_php_image_output_ctx(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHP_GDIMG_TYPE_GIF, "GIF", gdImageGifCtx);
 #else
 	_php_image_output(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHP_GDIMG_TYPE_GIF, "GIF", gdImageGif);
 #endif
 #else /* HAVE_GD_GIF */
-	php_error(E_WARNING, "ImageGif: No GIF support in this PHP build");
+	php_error(E_WARNING, "ImageGif: No GIF create support in this PHP build");
 	RETURN_FALSE;
 #endif /* HAVE_GD_GIF */
 }
@@ -2662,7 +2665,7 @@
 	fontname = (unsigned char *) Z_STRVAL_PP(FONTNAME);
 
 #ifdef USE_GD_IMGSTRTTF
-# if HAVE_LIBGD20 & HAVE_LIBFREETYPE
+# if HAVE_LIBFREETYPE
 	error = gdImageStringFT(im, brect, col, fontname, ptsize, angle, x, y, str);
 # else
 	error = gdImageStringTTF(im, brect, col, fontname, ptsize, angle, x, y, str);
@@ -3356,7 +3359,7 @@
 		}
 
 		switch (image_type) {
-#ifdef HAVE_GD_GIF
+#ifdef HAVE_GD_GIF_READ
 			case PHP_GDIMG_TYPE_GIF:
 				im_org = gdImageCreateFromGif (org);
 				if (im_org == NULL) {
@@ -3364,7 +3367,7 @@
 					RETURN_FALSE;
 				}
 				break;
-#endif /* HAVE_GD_GIF */
+#endif /* HAVE_GD_GIF_READ */
 
 #ifdef HAVE_GD_JPG
 			case PHP_GDIMG_TYPE_JPG:
