In file included from xine/kequalizer_plugin.cpp:51:
In file included from /usr/local/include/libavutil/mem.h:35:
In file included from /usr/local/include/libavutil/avutil.h:296:
/usr/local/include/libavutil/common.h:30:2: error: missing -D__STDC_CONSTANT_MACROS / #define __STDC_CONSTANT_MACROS
#error missing -D__STDC_CONSTANT_MACROS / #define __STDC_CONSTANT_MACROS
 ^

--- xine/kequalizer_plugin.cpp.orig	2011-01-19 19:20:53 UTC
+++ xine/kequalizer_plugin.cpp
@@ -37,6 +37,7 @@
 #include <cmath>
 
 #define __STDC_FORMAT_MACROS
+#define __STDC_CONSTANT_MACROS
 #include <inttypes.h>
 
 #include <xine.h>
@@ -48,6 +49,9 @@ extern "C" {
 #include <xine/xineutils.h>
 #undef this
 
+#include <libavutil/mem.h>
+
+
 #define KEQUALIZER_MAX_GAIN 12.0
 #define KEQUALIZER_L       2      // Storage for filter taps
 #define KEQUALIZER_KM      10     // Max number of bands 
@@ -281,7 +285,7 @@ static post_plugin_t *kequalizer_open_plugin(post_clas
     Q_UNUSED(video_target);
     kequalizer_plugin_t *that;
     //deprecated: kequalizer_plugin_t *that = static_cast<kequalizer_plugin_t *>(xine_xmalloc(sizeof(kequalizer_plugin_t)));
-    xine_xmalloc_aligned(2,sizeof(kequalizer_plugin_t),(void**)(&that));
+    that = (kequalizer_plugin_t *)av_mallocz(sizeof(kequalizer_plugin_t));
     post_in_t           *input;
     post_out_t          *output;
     xine_post_in_t      *input_api;
