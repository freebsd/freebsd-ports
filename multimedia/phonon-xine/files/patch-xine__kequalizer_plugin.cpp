--- ./xine/kequalizer_plugin.cpp.orig	2011-01-19 20:20:53.000000000 +0100
+++ ./xine/kequalizer_plugin.cpp	2012-03-12 11:12:12.244132405 +0100
@@ -48,6 +48,9 @@
 #include <xine/xineutils.h>
 #undef this
 
+#include <libavutil/mem.h>
+
+
 #define KEQUALIZER_MAX_GAIN 12.0
 #define KEQUALIZER_L       2      // Storage for filter taps
 #define KEQUALIZER_KM      10     // Max number of bands 
@@ -281,7 +284,7 @@
     Q_UNUSED(video_target);
     kequalizer_plugin_t *that;
     //deprecated: kequalizer_plugin_t *that = static_cast<kequalizer_plugin_t *>(xine_xmalloc(sizeof(kequalizer_plugin_t)));
-    xine_xmalloc_aligned(2,sizeof(kequalizer_plugin_t),(void**)(&that));
+    that = (kequalizer_plugin_t *)av_mallocz(sizeof(kequalizer_plugin_t));
     post_in_t           *input;
     post_out_t          *output;
     xine_post_in_t      *input_api;
