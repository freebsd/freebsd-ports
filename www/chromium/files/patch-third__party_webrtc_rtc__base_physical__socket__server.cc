--- third_party/webrtc/rtc_base/physical_socket_server.cc.orig	2024-06-17 12:56:06 UTC
+++ third_party/webrtc/rtc_base/physical_socket_server.cc
@@ -54,7 +54,7 @@
 #include "rtc_base/time_utils.h"
 #include "system_wrappers/include/field_trial.h"
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <linux/sockios.h>
 #endif
 
@@ -74,7 +74,7 @@ typedef void* SockOptArg;
 
 #endif  // WEBRTC_POSIX
 
-#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__)
+#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__) && !defined(WEBRTC_BSD)
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
@@ -329,7 +329,7 @@ int PhysicalSocket::GetOption(Option opt, int* value) 
     return -1;
   }
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     *value = (*value != IP_PMTUDISC_DONT) ? 1 : 0;
 #endif
   } else if (opt == OPT_DSCP) {
@@ -358,7 +358,7 @@ int PhysicalSocket::SetOption(Option opt, int value) {
   if (TranslateOption(opt, &slevel, &sopt) == -1)
     return -1;
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     value = (value) ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #endif
   } else if (opt == OPT_DSCP) {
@@ -389,7 +389,7 @@ int PhysicalSocket::SetOption(Option opt, int value) {
 int PhysicalSocket::Send(const void* pv, size_t cb) {
   int sent = DoSend(
       s_, reinterpret_cast<const char*>(pv), static_cast<int>(cb),
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
       // Suppress SIGPIPE. Without this, attempting to send on a socket whose
       // other end is closed will result in a SIGPIPE signal being raised to
       // our process, which by default will terminate the process, which we
@@ -418,7 +418,7 @@ int PhysicalSocket::SendTo(const void* buffer,
   size_t len = addr.ToSockAddrStorage(&saddr);
   int sent =
       DoSendTo(s_, static_cast<const char*>(buffer), static_cast<int>(length),
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
                // Suppress SIGPIPE. See above for explanation.
                MSG_NOSIGNAL,
 #else
@@ -697,7 +697,7 @@ int PhysicalSocket::TranslateOption(Option opt, int* s
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD) || defined(__native_client__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
@@ -746,7 +746,7 @@ int PhysicalSocket::TranslateOption(Option opt, int* s
       return -1;
 #endif
     case OPT_RECV_ECN:
-#if defined(WEBRTC_POSIX)
+#if defined(WEBRTC_POSIX) && defined(IP_RECVTOS) 
       if (family_ == AF_INET6) {
         *slevel = IPPROTO_IPV6;
         *sopt = IPV6_RECVTCLASS;
@@ -766,10 +766,19 @@ int PhysicalSocket::TranslateOption(Option opt, int* s
       *sopt = SO_KEEPALIVE;
       break;
     case OPT_TCP_KEEPCNT:
+#if !defined(TCP_KEEPCNT)
+      RTC_LOG(LS_WARNING) << "Socket::OPT_TCP_KEEPCNT not supported.";
+      return -1;
+#else
       *slevel = IPPROTO_TCP;
       *sopt = TCP_KEEPCNT;
       break;
+#endif
     case OPT_TCP_KEEPIDLE:
+#if !defined(TCP_KEEPALIVE)
+      RTC_LOG(LS_WARNING) << "Socket::OPT_TCP_KEEPALIVE not supported.";
+      return -1;
+#else
       *slevel = IPPROTO_TCP;
 #if !defined(WEBRTC_MAC)
       *sopt = TCP_KEEPIDLE;
@@ -777,12 +786,18 @@ int PhysicalSocket::TranslateOption(Option opt, int* s
       *sopt = TCP_KEEPALIVE;
 #endif
       break;
+#endif
     case OPT_TCP_KEEPINTVL:
+#if !defined(TCP_KEEPALIVE)
+      RTC_LOG(LS_WARNING) << "Socket::OPT_TCP_KEEPINTVL not supported.";
+      return -1;
+#else
       *slevel = IPPROTO_TCP;
       *sopt = TCP_KEEPINTVL;
       break;
+#endif
     case OPT_TCP_USER_TIMEOUT:
-#if defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#if (defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)) && defined(TCP_USER_TIMEOUT)
       *slevel = IPPROTO_TCP;
       *sopt = TCP_USER_TIMEOUT;
       break;
