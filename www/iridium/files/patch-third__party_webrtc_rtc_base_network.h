--- third_party/webrtc/rtc_base/network.h.orig	2017-09-07 00:56:08.460370000 +0200
+++ third_party/webrtc/rtc_base/network.h	2017-09-07 01:05:58.608460000 +0200
@@ -24,6 +24,10 @@
 #include "webrtc/rtc_base/networkmonitor.h"
 #include "webrtc/rtc_base/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
