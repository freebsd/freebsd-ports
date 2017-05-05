--- src/3rdparty/chromium/third_party/webrtc/modules/video_capture/device_info_impl.cc.orig	2017-04-19 18:46:33 UTC
+++ src/3rdparty/chromium/third_party/webrtc/modules/video_capture/device_info_impl.cc
@@ -11,6 +11,7 @@
 #include <assert.h>
 #include <stdlib.h>
 
+#include "webrtc/base/stringutils.h"
 #include "webrtc/modules/video_capture/device_info_impl.h"
 #include "webrtc/modules/video_capture/video_capture_config.h"
 #include "webrtc/system_wrappers/include/logging.h"
