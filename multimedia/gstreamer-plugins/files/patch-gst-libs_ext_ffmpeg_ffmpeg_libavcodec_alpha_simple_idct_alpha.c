--- gst-libs/ext/ffmpeg/ffmpeg/libavcodec/alpha/simple_idct_alpha.c.orig	Tue Mar 18 02:16:44 2003
+++ gst-libs/ext/ffmpeg/ffmpeg/libavcodec/alpha/simple_idct_alpha.c	Wed Mar 19 01:10:35 2003
@@ -27,6 +27,10 @@
 #include "asm.h"
 #include "../dsputil.h"
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
+typedef long int int_fast32_t;
+#endif
+
 extern void (*put_pixels_clamped_axp_p)(const DCTELEM *block, uint8_t *pixels,
                                         int line_size);
 extern void (*add_pixels_clamped_axp_p)(const DCTELEM *block, uint8_t *pixels, 
