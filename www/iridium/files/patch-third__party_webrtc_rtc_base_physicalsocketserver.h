--- third_party/webrtc/rtc_base/physicalsocketserver.h.orig	2017-09-07 05:58:03.996342000 +0200
+++ third_party/webrtc/rtc_base/physicalsocketserver.h	2017-09-07 05:58:28.882396000 +0200
@@ -11,7 +11,7 @@
 #ifndef WEBRTC_RTC_BASE_PHYSICALSOCKETSERVER_H_
 #define WEBRTC_RTC_BASE_PHYSICALSOCKETSERVER_H_
 
-#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX)
+#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <sys/epoll.h>
 #define WEBRTC_USE_EPOLL 1
 #endif
