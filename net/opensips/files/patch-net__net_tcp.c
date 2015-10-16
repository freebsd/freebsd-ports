--- net/net_tcp.c.orig	2015-04-22 08:20:03 UTC
+++ net/net_tcp.c
@@ -26,6 +26,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
