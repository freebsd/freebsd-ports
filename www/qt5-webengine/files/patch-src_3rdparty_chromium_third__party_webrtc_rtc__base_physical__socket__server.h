--- src/3rdparty/chromium/third_party/webrtc/rtc_base/physical_socket_server.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/physical_socket_server.h
@@ -11,7 +11,7 @@
 #ifndef RTC_BASE_PHYSICAL_SOCKET_SERVER_H_
 #define RTC_BASE_PHYSICAL_SOCKET_SERVER_H_
 
-#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX)
+#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <sys/epoll.h>
 #define WEBRTC_USE_EPOLL 1
 #endif
