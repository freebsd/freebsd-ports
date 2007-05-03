--- libavcodec/imgconvert.c.orig	Thu May  3 09:07:28 2007
+++ libavcodec/imgconvert.c	Thu May  3 09:08:25 2007
@@ -2319,7 +2319,6 @@
 }
 #endif
 
-#ifndef CONFIG_SWSCALER
 /* XXX: always use linesize. Return -1 if not supported */
 int img_convert(AVPicture *dst, int dst_pix_fmt,
                 const AVPicture *src, int src_pix_fmt,
@@ -2561,7 +2560,6 @@
     avpicture_free(tmp);
     return ret;
 }
-#endif
 
 /* NOTE: we scan all the pixels to have an exact information */
 static int get_alpha_info_pal8(const AVPicture *src, int width, int height)
