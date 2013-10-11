--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2013-10-09 17:35:26.000000000 +0200
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc	2013-10-09 17:32:54.000000000 +0200
@@ -14,6 +14,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 
 #include "webrtc/modules/rtp_rtcp/source/forward_error_correction_internal.h"
