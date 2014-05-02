--- ./third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2014-04-24 22:37:08.000000000 +0200
+++ ./third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc	2014-04-24 23:23:48.000000000 +0200
@@ -15,6 +15,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 
 #include "webrtc/modules/rtp_rtcp/interface/rtp_rtcp_defines.h"
