--- client/net_xfer.C.orig	Mon Sep 27 15:07:30 2004
+++ client/net_xfer.C	Thu Dec  2 21:00:11 2004
@@ -78,12 +78,10 @@
 
 #if defined(_WIN32)
 typedef int socklen_t;
-#elif defined ( __APPLE__)
+#elif defined(__APPLE__)
 typedef int32_t socklen_t;
-#elif !GETSOCKOPT_SOCKLEN_T
-#ifndef socklen_t
+#elif !defined(GETSOCKOPT_SOCKLEN_T) && !defined(_SOCKLEN_T_DECLARED) && !defined(socklen_t)
 typedef size_t socklen_t;
-#endif
 #endif
 
 using std::vector;
