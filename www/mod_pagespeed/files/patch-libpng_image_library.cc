--- net/instaweb/spriter/libpng_image_library.cc.orig	2011-09-29 17:45:52.000000000 +0000
+++ net/instaweb/spriter/libpng_image_library.cc	2011-09-29 17:46:17.000000000 +0000
@@ -235,7 +235,7 @@
     png_set_palette_to_rgb(png_struct);
   }
   if ((color_type == PNG_COLOR_TYPE_GRAY) && (bit_depth < 8)) {
-    png_set_gray_1_2_4_to_8(png_struct);
+    png_set_expand_gray_1_2_4_to_8(png_struct);
   }
   if (png_get_valid(png_struct, png_info, PNG_INFO_tRNS)) {
     png_set_tRNS_to_alpha(png_struct);
