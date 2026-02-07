--- src/3rdparty/chromium/third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "absl/algorithm/container.h"
