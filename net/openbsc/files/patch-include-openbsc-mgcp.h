--- include/openbsc/mgcp.h.orig	2015-02-10 22:03:25 UTC
+++ include/openbsc/mgcp.h
@@ -31,6 +31,11 @@
 
 #include <arpa/inet.h>
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #define RTP_PORT_DEFAULT 4000
 #define RTP_PORT_NET_DEFAULT 16000
 
