--- src/rtc_base/physical_socket_server.cc.orig	2021-06-27 05:27:48 UTC
+++ src/rtc_base/physical_socket_server.cc
@@ -51,6 +51,8 @@
 #include "rtc_base/synchronization/mutex.h"
 #include "rtc_base/time_utils.h"
 
+#undef WEBRTC_LINUX
+
 #if defined(WEBRTC_LINUX)
 #include <linux/sockios.h>
 #endif
@@ -70,7 +72,7 @@ typedef void* SockOptArg;
 
 #endif  // WEBRTC_POSIX
 
-#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__)
+#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__) && !defined(__FreeBSD__)
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
@@ -564,7 +566,7 @@ int PhysicalSocket::TranslateOption(Option opt, int* s
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__) || defined(__FreeBSD__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
