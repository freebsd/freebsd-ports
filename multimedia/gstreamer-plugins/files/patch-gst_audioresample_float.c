--- gst/audioresample/speex_resampler_float.c.orig	2012-07-17 09:48:45.000000000 +0200
+++ gst/audioresample/speex_resampler_float.c	2012-07-17 09:49:38.000000000 +0200
@@ -17,8 +17,20 @@
  * Boston, MA 02111-1307, USA.
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
 #define FLOATING_POINT
 #define OUTSIDE_SPEEX
 #define RANDOM_PREFIX resample_float
