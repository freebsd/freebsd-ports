--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.h
@@ -24,6 +24,10 @@
 #include "rtc_base/networkmonitor.h"
 #include "rtc_base/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
