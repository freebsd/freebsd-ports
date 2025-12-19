--- src/3rdparty/chromium/net/base/network_interfaces_posix.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/net/base/network_interfaces_posix.h
@@ -8,6 +8,8 @@
 // This file provides some basic functionality shared between
 // network_interfaces_linux.cc and network_interfaces_getifaddrs.cc.
 
+#include <sys/socket.h>
+
 #include <string>
 
 struct sockaddr;
