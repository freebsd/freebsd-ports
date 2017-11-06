--- src/vpninfo.h.orig	2016-08-28 20:11:26 UTC
+++ src/vpninfo.h
@@ -23,7 +23,7 @@
 #ifdef _WIN32
 #include <winsock2.h>
 #endif
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define SOCKET int
 #endif
 
