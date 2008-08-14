--- libavcodec/imgconvert.c.orig	2008-08-14 14:31:37.000000000 -0400
+++ libavcodec/imgconvert.c	2008-08-14 14:31:54.000000000 -0400
@@ -2108,7 +2108,6 @@ int img_pad(AVPicture *dst, const AVPict
 }
 #endif
 
-#ifndef CONFIG_SWSCALE
 static uint8_t y_ccir_to_jpeg[256];
 static uint8_t y_jpeg_to_ccir[256];
 static uint8_t c_ccir_to_jpeg[256];
@@ -2628,7 +2627,6 @@ int img_convert(AVPicture *dst, int dst_
     avpicture_free(tmp);
     return ret;
 }
-#endif
 
 /* NOTE: we scan all the pixels to have an exact information */
 static int get_alpha_info_pal8(const AVPicture *src, int width, int height)
