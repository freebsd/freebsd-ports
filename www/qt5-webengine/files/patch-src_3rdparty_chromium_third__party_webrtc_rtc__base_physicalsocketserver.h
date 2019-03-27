--- src/3rdparty/chromium/third_party/webrtc/rtc_base/physicalsocketserver.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/physicalsocketserver.h
@@ -11,7 +11,7 @@
 #ifndef RTC_BASE_PHYSICALSOCKETSERVER_H_
 #define RTC_BASE_PHYSICALSOCKETSERVER_H_
 
-#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX)
+#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <sys/epoll.h>
 #define WEBRTC_USE_EPOLL 1
 #endif
