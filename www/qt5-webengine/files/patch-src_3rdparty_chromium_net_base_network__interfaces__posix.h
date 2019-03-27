--- src/3rdparty/chromium/net/base/network_interfaces_posix.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/base/network_interfaces_posix.h
@@ -8,6 +8,8 @@
 // This file provides some basic functionality shared between
 // network_interfaces_linux.cc and network_interfaces_getifaddrs.cc.
 
+#include <sys/socket.h>
+
 #include <string>
 
 struct sockaddr;
