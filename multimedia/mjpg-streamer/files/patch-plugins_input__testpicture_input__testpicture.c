--- plugins/input_testpicture/input_testpicture.c.orig	2021-08-17 01:24:22 UTC
+++ plugins/input_testpicture/input_testpicture.c
@@ -34,7 +34,7 @@
 #include <pthread.h>
 #include <syslog.h>
 
-#include <linux/types.h>          /* for videodev2.h */
+#include <sys/types.h>          /* for videodev2.h */
 #include <linux/videodev2.h>
 
 #include "../../mjpg_streamer.h"
