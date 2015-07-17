--- dhcprelay.c.orig	2006-03-21 02:46:28 UTC
+++ dhcprelay.c
@@ -186,7 +186,7 @@ void pcap_callback(u_char *user, const s
 	printf(" %d",eh->ether_type);
     }
     // check for IPv4 packets
-    if (eh->ether_type!=8) { 
+    if (eh->ether_type != htons(0x800)) { 
 	if (DEBUG>1) printf("\n");
 	return;
     }
