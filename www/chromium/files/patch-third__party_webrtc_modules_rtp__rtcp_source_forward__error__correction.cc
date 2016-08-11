--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2016-05-11 19:04:03 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -14,6 +14,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 
 #include "webrtc/base/checks.h"
