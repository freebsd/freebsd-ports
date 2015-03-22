--- src/dhcp_probe.h.orig	2015-01-03 11:43:49.000000000 -0500
+++ src/dhcp_probe.h	2015-01-03 11:44:11.000000000 -0500
@@ -18,7 +18,7 @@
 
 extern int sockfd; /* general purpose datagram socket fd for temp use throughout */
 
-extern struct ether_addr my_eaddr;
+extern struct libnet_ether_addr my_eaddr;
 
 
 
