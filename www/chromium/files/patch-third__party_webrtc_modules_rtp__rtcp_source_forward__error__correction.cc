--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2019-06-04 18:58:07 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -12,6 +12,7 @@
 
 #include <string.h>
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "absl/algorithm/container.h"
