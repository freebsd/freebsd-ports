--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2019-09-09 21:57:05 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "absl/algorithm/container.h"
