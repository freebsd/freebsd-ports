--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2014-10-02 17:40:34 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -15,6 +15,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 
 #include "webrtc/modules/rtp_rtcp/interface/rtp_rtcp_defines.h"
