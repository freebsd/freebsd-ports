--- gst-libs/ext/ffmpeg/ffmpeg/libavcodec/alpha/simple_idct_alpha.c.orig	Fri Apr 25 22:06:13 2003
+++ gst-libs/ext/ffmpeg/ffmpeg/libavcodec/alpha/simple_idct_alpha.c	Fri Apr 25 23:19:39 2003
@@ -24,8 +24,14 @@
  *                     and Falk Hueffner <falk@debian.org>
  */
 
+#include <sys/param.h>
+
 #include "asm.h"
 #include "../dsputil.h"
+
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
+typedef __int32_t int_fast32_t;
+#endif
 
 extern void (*put_pixels_clamped_axp_p)(const DCTELEM *block, uint8_t *pixels,
                                         int line_size);
