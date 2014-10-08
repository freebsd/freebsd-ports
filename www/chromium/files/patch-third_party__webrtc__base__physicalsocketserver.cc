--- third_party/webrtc/base/physicalsocketserver.cc.orig	2014-10-02 17:40:33 UTC
+++ third_party/webrtc/base/physicalsocketserver.cc
@@ -240,7 +240,7 @@
     socklen_t optlen = sizeof(*value);
     int ret = ::getsockopt(s_, slevel, sopt, (SockOptArg)value, &optlen);
     if (ret != -1 && opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
       *value = (*value != IP_PMTUDISC_DONT) ? 1 : 0;
 #endif
     }
@@ -253,7 +253,7 @@
     if (TranslateOption(opt, &slevel, &sopt) == -1)
       return -1;
     if (opt == OPT_DONTFRAGMENT) {
-#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_ANDROID) && !defined(WEBRTC_BSD)
       value = (value) ? IP_PMTUDISC_DO : IP_PMTUDISC_DONT;
 #endif
     }
@@ -503,10 +503,10 @@
         *slevel = IPPROTO_IP;
         *sopt = IP_DONTFRAGMENT;
         break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD) || defined(__native_client__)
         LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
         return -1;
-#elif defined(WEBRTC_POSIX)
+#elif defined(WEBRTC_POSIX) && !defined(WEBRTC_BSD)
         *slevel = IPPROTO_IP;
         *sopt = IP_MTU_DISCOVER;
         break;
