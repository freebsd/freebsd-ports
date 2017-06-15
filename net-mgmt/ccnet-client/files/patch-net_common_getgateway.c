--- net/common/getgateway.c.orig	2015-11-11 09:50:52 UTC
+++ net/common/getgateway.c
@@ -34,7 +34,7 @@
 #undef USE_SYSCTL_NET_ROUTE
 #endif
 
-#ifdef BSD
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #undef USE_PROC_NET_ROUTE
 #define USE_SOCKET_ROUTE
 #undef USE_SYSCTL_NET_ROUTE
