--- ./net/base/net_util.cc.orig	2010-12-16 02:11:31.000000000 +0100
+++ ./net/base/net_util.cc	2010-12-20 20:15:08.000000000 +0100
@@ -25,9 +25,9 @@
 #include <fcntl.h>
 #include <ifaddrs.h>
 #include <netdb.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <netinet/in.h>
-#include <sys/socket.h>
 #endif
 
 #include "base/base64.h"
