--- third_party/webrtc/rtc_base/network.h.orig	2021-12-14 11:47:22 UTC
+++ third_party/webrtc/rtc_base/network.h
@@ -31,6 +31,10 @@
 #include "rtc_base/third_party/sigslot/sigslot.h"
 #include "rtc_base/thread_annotations.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
