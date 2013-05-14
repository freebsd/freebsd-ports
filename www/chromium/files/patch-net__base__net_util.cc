--- net/base/net_util.cc.orig	2013-02-28 10:14:41.000000000 +0200
+++ net/base/net_util.cc	2013-03-06 21:34:27.000000000 +0200
@@ -22,6 +22,7 @@
 #endif
 #include <net/if.h>
 #include <netdb.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #endif
 
