--- third_party/webrtc/base/network.h.orig	2014-10-10 09:16:13 UTC
+++ third_party/webrtc/base/network.h
@@ -21,6 +21,10 @@
 #include "webrtc/base/messagehandler.h"
 #include "webrtc/base/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
