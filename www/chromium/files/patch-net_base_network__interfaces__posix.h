--- net/base/network_interfaces_posix.h.orig	2017-07-04 22:49:41.402276000 +0200
+++ net/base/network_interfaces_posix.h	2017-07-04 22:49:59.456467000 +0200
@@ -8,6 +8,8 @@
 // This file is only used to expose some of the internals of
 // network_interfaces_posix.cc to network_interfaces_linux.cc and network_interfaces_mac.cc.
 
+#include <sys/socket.h>
+
 #include <string>
 
 struct sockaddr;
