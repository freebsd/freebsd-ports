--- src/display/png.c.orig	2013-05-12 15:16:43 UTC
+++ src/display/png.c
@@ -132,9 +132,9 @@ int png_load_img(img I) {
     /* Convert greyscale images to 8-bit RGB */
     if (color_type == PNG_COLOR_TYPE_GRAY ||
         color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
-        if (bit_depth < 8) {
+        /* if (bit_depth < 8) {
             png_set_gray_1_2_4_to_8(png_ptr);
-        }
+        } */
         png_set_gray_to_rgb(png_ptr);
     }
 
