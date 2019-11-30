--- client/v4l/cx88_radio_capture.h.orig	2019-11-30 20:23:39 UTC
+++ client/v4l/cx88_radio_capture.h
@@ -32,7 +32,7 @@
 #include <linux/videodev2.h>
 extern "C"
 {
-   #include <cuse4bsd.h>
+   #include <cuse.h>
 }
 #include "cx88_capture.h"
 #include "tuner_config.h"
