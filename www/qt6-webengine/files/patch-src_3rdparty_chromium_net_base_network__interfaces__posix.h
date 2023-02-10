--- src/3rdparty/chromium/net/base/network_interfaces_posix.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/base/network_interfaces_posix.h
@@ -8,6 +8,8 @@
 // This file provides some basic functionality shared between
 // network_interfaces_linux.cc and network_interfaces_getifaddrs.cc.
 
+#include <sys/socket.h>
+
 #include <string>
 
 struct sockaddr;
