--- src/bootp.c.orig	2015-01-03 11:14:43.000000000 -0500
+++ src/bootp.c	2015-01-16 00:27:42.000000000 -0500
@@ -11,6 +11,7 @@
 #include "bootp.h"
 #include "configfile.h"
 #include "report.h"
+#include "utils.h"
 
 
 
@@ -20,7 +21,7 @@
 unsigned char vendor_option_end[] = VENDOR_OPTION_END;
 unsigned char vendor_option_dhcpmessagetype_dhcpdiscover[] = VENDOR_OPTION_DHCPDISCOVER;
 unsigned char vendor_option_dhcpmessagetype_dhcprequest[]  = VENDOR_OPTION_DHCPREQUEST;
-unsigned char vendor_option_clientid[1 + 1 + 1 + sizeof(struct ether_addr)]; /* option code, length byte,  htype byte, ether_addr */
+unsigned char vendor_option_clientid[1 + 1 + 1 + sizeof(struct libnet_ether_addr)]; /* option code, length byte,  htype byte, ether_addr */
 unsigned char vendor_option_serverid[1 + 1 + 4]; /* option code, length byte, ip_addr */
 unsigned char vendor_option_requestedipaddr[1 + 1 + 4]; /* option code, length byte, ip_addr */
 
@@ -73,7 +74,7 @@
 		char label[NUM_FLAVORS_MAXSTRING];
 		snprintf(label, sizeof(label)-1, "%d", i);
 		if (libnet_cq_add(l, label) == -1) {
-			report(LOG_ERR, "init_libnet_context_queue: libnet_cq_add: error adding libnet context '%s' to queue: %s", label, libnet_errbuf);
+			report(LOG_ERR, "init_libnet_context_queue: libnet_cq_add: error adding libnet context '%s' to queue: %s", label, libnet_geterror(l));
 			return(0);
 		}
 	}
@@ -124,7 +125,7 @@
 	packet->bootp_hlen = HLEN_ETHER;
 	packet->bootp_xid = BOOTP_XID;
 	packet->bootp_op = BOOTREQUEST;
-	bcopy(GetChaddr(), &packet->bootp_chaddr, sizeof(struct ether_addr));
+	bcopy(GetChaddr(), &packet->bootp_chaddr, sizeof(struct libnet_ether_addr));
 
 	/* add RFC1048 cookie to options field */
 	insert_option(&next_vendor_option, vendor_option_vm_cookie_rfc1048, sizeof(vendor_option_vm_cookie_rfc1048));
@@ -311,11 +312,11 @@
 	vendor_option_clientid[0] = VENDOR_OPTION_CLIENTID;
 
 	/* length byte */
-	vendor_option_clientid[1] = 1 + sizeof(struct ether_addr);
+	vendor_option_clientid[1] = 1 + sizeof(struct libnet_ether_addr);
 
 	/* fill in clientid value: htype code followed by enet addr */
 	vendor_option_clientid[2] = 0x01;
-	bcopy(GetChaddr(), vendor_option_clientid+3, sizeof(struct ether_addr));
+	bcopy(GetChaddr(), vendor_option_clientid+3, sizeof(struct libnet_ether_addr));
 
 	return;
 }
