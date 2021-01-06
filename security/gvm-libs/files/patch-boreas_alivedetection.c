--- boreas/alivedetection.c.orig	2020-12-30 23:49:07.498953000 -0500
+++ boreas/alivedetection.c	2020-12-30 23:50:37.570417000 -0500
@@ -39,7 +39,12 @@
 #include <netinet/ip6.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/tcp.h>
-#include <netpacket/packet.h> /* for sockaddr_ll */
+#ifdef AF_LINK
+#   include <net/if_dl.h>
+#endif
+#ifdef AF_PACKET
+#   include <netpacket/packet.h>
+#endif
 #include <pcap.h>
 #include <pthread.h>
 #include <stdlib.h>
