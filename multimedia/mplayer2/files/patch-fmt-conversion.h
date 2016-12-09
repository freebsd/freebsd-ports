--- fmt-conversion.h.orig	2016-11-29 15:06:09 UTC
+++ fmt-conversion.h
@@ -22,7 +22,7 @@
 #include "libavutil/avutil.h"
 #include <libavutil/pixfmt.h>

-enum PixelFormat imgfmt2pixfmt(int fmt);
-int pixfmt2imgfmt(enum PixelFormat pix_fmt);
+enum AVPixelFormat imgfmt2pixfmt(int fmt);
+int pixfmt2imgfmt(enum AVPixelFormat pix_fmt);

 #endif /* MPLAYER_FMT_CONVERSION_H */
