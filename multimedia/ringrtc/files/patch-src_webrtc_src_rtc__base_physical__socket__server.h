--- src/webrtc/src/rtc_base/physical_socket_server.h.orig	2021-01-28 23:16:17 UTC
+++ src/webrtc/src/rtc_base/physical_socket_server.h
@@ -14,7 +14,7 @@
 #include "api/units/time_delta.h"
 
 #if defined(WEBRTC_POSIX)
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 // On Linux, use epoll.
 #include <sys/epoll.h>
 #define WEBRTC_USE_EPOLL 1
