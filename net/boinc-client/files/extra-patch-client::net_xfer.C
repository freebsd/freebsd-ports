--- client/net_xfer.C.orig	Tue Dec 21 13:25:39 2004
+++ client/net_xfer.C	Tue Dec 21 13:28:15 2004
@@ -80,7 +80,7 @@
 typedef int socklen_t;
 #elif defined(__APPLE__)
 typedef int32_t socklen_t;
-#elif !defined(GETSOCKOPT_SOCKLEN_T) && !defined(_SOCKLEN_T_DECLARED) && !defined(socklen_t)
+#elif !defined(__FreeBSD__)
 typedef size_t socklen_t;
 #endif
 
