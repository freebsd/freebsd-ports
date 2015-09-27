--- third_party/webrtc/base/linux.cc.orig	2015-09-26 19:26:54.911449000 +0200
+++ third_party/webrtc/base/linux.cc	2015-09-26 19:29:09.372270000 +0200
@@ -8,7 +8,7 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include "webrtc/base/linux.h"
 
 #include <ctype.h>
@@ -288,4 +288,4 @@
 
 }  // namespace rtc
 
-#endif  // defined(WEBRTC_LINUX)
+#endif  // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
