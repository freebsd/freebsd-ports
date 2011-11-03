--- net/instaweb/spriter/libpng_image_library.cc.orig	2011-10-31 14:25:06.000000000 +0000
+++ net/instaweb/spriter/libpng_image_library.cc	2011-10-31 18:18:29.000000000 +0000
@@ -235,7 +235,11 @@
     png_set_palette_to_rgb(png_struct);
   }
   if ((color_type == PNG_COLOR_TYPE_GRAY) && (bit_depth < 8)) {
+#if ((PNG_LIBPNG_VER_MAJOR==1 && PNG_LIBPNG_VER_MINOR>=4) || PNG_LIBPNG_VER_MAJOR>1)
+    png_set_expand_gray_1_2_4_to_8(png_struct);
+#else
     png_set_gray_1_2_4_to_8(png_struct);
+#endif
   }
   if (png_get_valid(png_struct, png_info, PNG_INFO_tRNS)) {
     png_set_tRNS_to_alpha(png_struct);
