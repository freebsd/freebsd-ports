--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2013-09-03 03:23:27.000000000 -0400
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc	2013-09-12 14:54:49.000000000 -0400
@@ -12,6 +12,7 @@
 
 #include <algorithm>
 #include <cassert>
+#include <cstdlib>
 #include <cstring>
 #include <iterator>
 
