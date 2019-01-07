--- third_party/webrtc/rtc_base/physicalsocketserver.cc.orig	2018-12-03 21:20:27.000000000 +0100
+++ third_party/webrtc/rtc_base/physicalsocketserver.cc	2018-12-15 16:59:55.918713000 +0100
@@ -66,7 +66,7 @@
 
 #endif  // WEBRTC_POSIX
 
-#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(__native_client__)
+#if defined(WEBRTC_POSIX) && !defined(WEBRTC_MAC) && !defined(WEBRTC_BSD) && !defined(__native_client__)
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
@@ -286,7 +286,7 @@
   socklen_t optlen = sizeof(*value);
   int ret = ::getsockopt(s_, slevel, sopt, (SockOptArg)value, &optlen);
   if (ret != -1 && opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     *value = (*value != IP_PMTUDISC_DONT) ? 1 : 0;
 #endif
   }
@@ -299,7 +299,7 @@
   if (TranslateOption(opt, &slevel, &sopt) == -1)
     return -1;
   if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
     value = (value) ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #endif
   }
@@ -309,7 +309,7 @@
 int PhysicalSocket::Send(const void* pv, size_t cb) {
   int sent = DoSend(
       s_, reinterpret_cast<const char*>(pv), static_cast<int>(cb),
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
       // Suppress SIGPIPE. Without this, attempting to send on a socket whose
       // other end is closed will result in a SIGPIPE signal being raised to
       // our process, which by default will terminate the process, which we
@@ -338,7 +338,7 @@
   size_t len = addr.ToSockAddrStorage(&saddr);
   int sent =
       DoSendTo(s_, static_cast<const char*>(buffer), static_cast<int>(length),
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
                // Suppress SIGPIPE. See above for explanation.
                MSG_NOSIGNAL,
 #else
@@ -529,7 +529,7 @@
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD) || defined(__native_client__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
