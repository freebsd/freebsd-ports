--- src/rtc_base/physical_socket_server.h.orig	2021-02-03 11:42:41 UTC
+++ src/rtc_base/physical_socket_server.h
@@ -12,8 +12,6 @@
 #define RTC_BASE_PHYSICAL_SOCKET_SERVER_H_
 
 #if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX)
-#include <sys/epoll.h>
-#define WEBRTC_USE_EPOLL 1
 #endif
 
 #include <array>
