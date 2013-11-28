--- gst/audioresample/speex_resampler_float.c.orig	2013-04-26 08:20:28.000000000 +0200
+++ gst/audioresample/speex_resampler_float.c	2013-10-20 17:32:45.000000000 +0200
@@ -17,8 +17,20 @@
  * Boston, MA 02110-1301, USA.
  */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+#ifdef _USE_SSE
+#ifndef HAVE_XMMINTRIN_H
+#undef _USE_SSE
+#undef _USE_SSE2
+#else
 #define _USE_SSE
 #define _USE_SSE2
+#endif
+#endif
+
 #define _USE_NEON
 #define FLOATING_POINT
 #define OUTSIDE_SPEEX
