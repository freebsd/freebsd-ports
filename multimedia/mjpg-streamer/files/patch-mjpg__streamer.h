--- mjpg_streamer.h.orig	2021-08-17 00:59:00 UTC
+++ mjpg_streamer.h
@@ -29,6 +29,7 @@
 #define MAX_OUTPUT_PLUGINS 10
 #define MAX_PLUGIN_ARGUMENTS 32
 
+#include <netinet/in.h>
 #include <linux/types.h>          /* for videodev2.h */
 #include <linux/videodev2.h>
 #include <pthread.h>
