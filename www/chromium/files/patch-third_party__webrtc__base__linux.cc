--- third_party/webrtc/base/linux.cc.orig	2014-10-02 17:40:33 UTC
+++ third_party/webrtc/base/linux.cc
@@ -8,7 +8,7 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include "webrtc/base/linux.h"
 
 #include <ctype.h>
@@ -345,4 +345,4 @@
 
 }  // namespace rtc
 
-#endif  // defined(WEBRTC_LINUX)
+#endif  // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
