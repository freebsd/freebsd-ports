--- third_party/webrtc/rtc_base/physical_socket_server.h.orig	2026-01-16 13:40:34 UTC
+++ third_party/webrtc/rtc_base/physical_socket_server.h
@@ -22,7 +22,7 @@
 #include "rtc_base/socket_address.h"
 
 #if defined(WEBRTC_POSIX)
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 // On Linux, use epoll.
 #include <sys/epoll.h>
 
