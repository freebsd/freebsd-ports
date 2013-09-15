--- third_party/webrtc/video_engine/stream_synchronization.cc.orig	2013-09-03 03:23:20.000000000 -0400
+++ third_party/webrtc/video_engine/stream_synchronization.cc	2013-09-12 15:58:27.000000000 -0400
@@ -12,7 +12,7 @@
 
 #include <algorithm>
 #include <assert.h>
-#include <cmath>
+#include <cstdlib>
 
 #include "webrtc/system_wrappers/interface/trace.h"
 
