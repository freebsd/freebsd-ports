--- src/net.h.orig	2008-05-05 19:05:21.000000000 +0200
+++ src/net.h	2013-02-18 07:48:54.000000000 +0100
@@ -26,6 +26,7 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <netinet/udp.h>
 #include <arpa/inet.h>
 #include <pcap.h>
 #include <libnet.h>
