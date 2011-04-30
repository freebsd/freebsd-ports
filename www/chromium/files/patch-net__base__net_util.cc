--- net/base/net_util.cc.orig	2011-02-17 10:52:37.000000000 +0100
+++ net/base/net_util.cc	2011-02-20 21:20:04.000000000 +0100
@@ -24,6 +24,7 @@
 #include <fcntl.h>
 #include <ifaddrs.h>
 #include <netdb.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <netinet/in.h>
 #endif
