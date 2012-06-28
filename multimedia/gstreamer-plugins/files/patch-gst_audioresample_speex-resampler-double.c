--- gst/audioresample/speex_resampler_double.c.orig	2012-06-28 10:31:31.000000000 +0200
+++ gst/audioresample/speex_resampler_double.c	2012-06-28 10:33:01.000000000 +0200
@@ -17,7 +17,18 @@
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
 #define _USE_SSE2
+#endif
+#endif
 #define FLOATING_POINT
 #define DOUBLE_PRECISION
 #define OUTSIDE_SPEEX
