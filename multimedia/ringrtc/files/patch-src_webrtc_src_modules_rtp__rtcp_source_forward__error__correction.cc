--- ../../src/webrtc/src/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2021-01-28 23:16:17 UTC
+++ ../../src/webrtc/src/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "absl/algorithm/container.h"
