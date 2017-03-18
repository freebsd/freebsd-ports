--- third_party/webrtc/base/network.h.orig	2017-03-09 20:05:29 UTC
+++ third_party/webrtc/base/network.h
@@ -24,6 +24,10 @@
 #include "webrtc/base/messagehandler.h"
 #include "webrtc/base/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
