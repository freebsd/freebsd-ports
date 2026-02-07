--- src/dhcp_probe.h.orig	2021-01-18 19:16:27 UTC
+++ src/dhcp_probe.h
@@ -18,7 +18,7 @@ extern int vlan_id;
 
 extern int sockfd; /* general purpose datagram socket fd for temp use throughout */
 
-extern struct ether_addr my_eaddr;
+extern struct libnet_ether_addr my_eaddr;
 
 
 
