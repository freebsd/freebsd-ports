--- src/3rdparty/chromium/third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2017-01-26 00:50:17 UTC
+++ src/3rdparty/chromium/third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 #include <utility>
 
