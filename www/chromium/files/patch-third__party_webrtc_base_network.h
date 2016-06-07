--- third_party/webrtc/base/network.h.orig	2016-05-11 19:04:03 UTC
+++ third_party/webrtc/base/network.h
@@ -23,6 +23,10 @@
 #include "webrtc/base/scoped_ptr.h"
 #include "webrtc/base/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
