--- net/common/getgateway.c.orig	2014-07-28 14:30:13.000000000 -0400
+++ net/common/getgateway.c	2014-07-28 14:30:29.000000000 -0400
@@ -34,7 +34,7 @@
 #undef USE_SYSCTL_NET_ROUTE
 #endif
 
-#ifdef BSD
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #undef USE_PROC_NET_ROUTE
 #define USE_SOCKET_ROUTE
 #undef USE_SYSCTL_NET_ROUTE
