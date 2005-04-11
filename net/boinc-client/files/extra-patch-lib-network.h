--- lib/network.h.orig	Mon Mar  7 16:19:09 2005
+++ lib/network.h	Sun Mar 20 22:35:20 2005
@@ -25,7 +25,7 @@
 #define SHUT_WR SD_SEND
 #elif defined( __APPLE__)
 typedef int32_t socklen_t;
-#elif !defined(GETSOCKOPT_SOCKLEN_T) && !defined(_SOCKLEN_T_DECLARED) && !defined(socklen_t)
+#elif !defined(__FreeBSD__)
 typedef size_t socklen_t;
 #endif
 
