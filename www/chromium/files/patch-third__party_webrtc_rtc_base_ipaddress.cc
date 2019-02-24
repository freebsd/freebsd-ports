--- third_party/webrtc/rtc_base/ipaddress.cc.orig	2019-02-01 23:33:19.402949000 +0100
+++ third_party/webrtc/rtc_base/ipaddress.cc	2019-02-01 23:42:10.940296000 +0100
@@ -11,6 +11,9 @@
 #if defined(WEBRTC_POSIX)
 #include <netinet/in.h>
 #include <sys/socket.h>
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
 #ifdef OPENBSD
 #include <netinet/in_systm.h>
 #endif
