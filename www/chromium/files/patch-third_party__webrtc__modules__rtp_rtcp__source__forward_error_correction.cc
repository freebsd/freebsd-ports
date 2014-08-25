--- ./third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2014-08-20 21:04:19.000000000 +0200
+++ ./third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc	2014-08-22 15:06:27.000000000 +0200
@@ -15,6 +15,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 
 #include "webrtc/modules/rtp_rtcp/interface/rtp_rtcp_defines.h"
