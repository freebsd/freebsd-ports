--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2017-04-19 19:07:53 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 #include <utility>
 
