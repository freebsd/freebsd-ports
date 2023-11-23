--- src/3rdparty/chromium/third_party/webrtc/rtc_base/physical_socket_server.h.orig	2022-10-24 13:33:33 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/physical_socket_server.h
@@ -12,7 +12,7 @@
 #define RTC_BASE_PHYSICAL_SOCKET_SERVER_H_
 
 #include "api/units/time_delta.h"
-#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX)
+#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <sys/epoll.h>
 #define WEBRTC_USE_EPOLL 1
 #endif
