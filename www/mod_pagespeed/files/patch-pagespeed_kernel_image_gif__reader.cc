--- pagespeed/kernel/image/gif_reader.cc.orig	2017-09-13 22:14:53 UTC
+++ pagespeed/kernel/image/gif_reader.cc
@@ -411,8 +411,8 @@ bool ReadGifToPng(GifFileType* gif_file,
   png_uint_32 height = png_get_image_height(paletted_png_ptr,
                                             paletted_info_ptr);
   for (png_uint_32 row = 1; row < height; ++row) {
-    memcpy(paletted_info_ptr->row_pointers[row],
-           paletted_info_ptr->row_pointers[0],
+    memcpy(/*paletted_info_ptr->*/row_pointers[row],
+           /*paletted_info_ptr->*/row_pointers[0],
            row_size);
   }
 
