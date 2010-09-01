--- ./src/net/socket.cpp.orig	2010-06-14 20:29:14.000000000 +0400
+++ ./src/net/socket.cpp	2010-06-16 01:32:57.006817314 +0400
@@ -54,6 +54,15 @@
 #define errno WSAGetLastError()
 #endif
 #include <kdebug.h>
+
+#ifndef SOL_IP
+#define SOL_IP IPPROTO_IP
+#endif
+
+#ifndef SOL_IPV6
+#define SOL_IPV6 IPPROTO_IPV6
+#endif
+
 using namespace bt;
 
 namespace net
