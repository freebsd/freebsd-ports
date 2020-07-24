--- third_party/webrtc/rtc_base/physical_socket_server.cc.orig	2020-03-16 18:42:14 UTC
+++ third_party/webrtc/rtc_base/physical_socket_server.cc
@@ -51,7 +51,7 @@
 #include "rtc_base/null_socket_server.h"
 #include "rtc_base/time_utils.h"
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <linux/sockios.h>
 #endif
 
@@ -70,7 +70,7 @@ typedef void* SockOptArg;
 
 #endif  // WEBRTC_POSIX
 
-#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__)
+#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(WEBRTC_BSD) && !defined(__native_client__)
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
@@ -290,7 +290,7 @@ int PhysicalSocket::GetOption(Option opt, int* value) 
   socklen_t optlen = sizeof(*value);
   int ret = ::getsockopt(s_, slevel, sopt, (SockOptArg)value, &optlen);
   if (ret != -1 && opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     *value = (*value != IP_PMTUDISC_DONT) ? 1 : 0;
 #endif
   }
@@ -303,7 +303,7 @@ int PhysicalSocket::SetOption(Option opt, int value) {
   if (TranslateOption(opt, &slevel, &sopt) == -1)
     return -1;
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     value = (value) ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #endif
   }
@@ -533,7 +533,7 @@ int PhysicalSocket::TranslateOption(Option opt, int* s
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD) || defined(__native_client__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
