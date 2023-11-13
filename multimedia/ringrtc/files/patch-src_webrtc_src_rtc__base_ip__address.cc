--- src/webrtc/src/rtc_base/ip_address.cc.orig	2021-01-28 23:16:17 UTC
+++ src/webrtc/src/rtc_base/ip_address.cc
@@ -11,6 +11,9 @@
 #if defined(WEBRTC_POSIX)
 #include <netinet/in.h>
 #include <sys/socket.h>
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
 
 #include "absl/strings/string_view.h"
 #ifdef OPENBSD
