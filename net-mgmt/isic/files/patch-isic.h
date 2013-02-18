--- isic.h.orig	2006-12-16 01:08:44.000000000 +0100
+++ isic.h	2013-02-18 07:36:38.000000000 +0100
@@ -5,11 +5,15 @@
 #endif
 
 #include <libnet.h>
+#include <libnet/libnet-headers.h>
 
+#include <netinet/ip.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/icmp6.h>
 #include <netinet/ip6.h>
 #include <netinet/if_ether.h>
+#include <netinet/udp.h>
+#include <netinet/tcp.h>
 
 #ifndef ETHER_FRAME_SIZE
 #define ETHER_FRAME_SIZE 1500
