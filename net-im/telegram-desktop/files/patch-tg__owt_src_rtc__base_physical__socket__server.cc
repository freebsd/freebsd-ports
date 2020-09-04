--- tg_owt/src/rtc_base/physical_socket_server.cc.orig	2020-08-30 09:41:57 UTC
+++ tg_owt/src/rtc_base/physical_socket_server.cc
@@ -51,6 +51,8 @@
 #include "rtc_base/null_socket_server.h"
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
@@ -551,7 +553,7 @@ int PhysicalSocket::TranslateOption(Option opt, int* s
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__) || defined(__FreeBSD__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
