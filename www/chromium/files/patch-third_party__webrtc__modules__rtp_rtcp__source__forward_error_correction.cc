--- ./third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2014-04-30 22:44:21.000000000 +0200
+++ ./third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc	2014-05-04 14:38:49.000000000 +0200
@@ -15,6 +15,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 
 #include "webrtc/modules/rtp_rtcp/interface/rtp_rtcp_defines.h"
