--- ./src/net/SipUserAgent.cpp.orig	Thu Dec 28 17:59:14 2006
+++ ./src/net/SipUserAgent.cpp	Thu Dec 28 18:00:20 2006
@@ -83,6 +83,8 @@
 #  define PLATFORM_UA_PARAM " (Linux)"
 #elif defined(sun)
 #  define PLATFORM_UA_PARAM " (Solaris)"
+#elif defined(__FreeBSD__)
+#  define PLATFORM_UA_PARAM " (FreeBSD)"
 #endif
 #endif /* PLATFORM_UA_PARAM */
 
