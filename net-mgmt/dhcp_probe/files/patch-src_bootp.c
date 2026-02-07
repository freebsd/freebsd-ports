--- src/bootp.c.orig	2021-01-18 19:18:24 UTC
+++ src/bootp.c
@@ -21,7 +21,7 @@ unsigned char vendor_option_vm_cookie_rfc1048[] = VEND
 unsigned char vendor_option_end[] = VENDOR_OPTION_END;
 unsigned char vendor_option_dhcpmessagetype_dhcpdiscover[] = VENDOR_OPTION_DHCPDISCOVER;
 unsigned char vendor_option_dhcpmessagetype_dhcprequest[]  = VENDOR_OPTION_DHCPREQUEST;
-unsigned char vendor_option_clientid[1 + 1 + 1 + sizeof(struct ether_addr)]; /* option code, length byte,  htype byte, ether_addr */
+unsigned char vendor_option_clientid[1 + 1 + 1 + sizeof(struct libnet_ether_addr)]; /* option code, length byte,  htype byte, ether_addr */
 unsigned char vendor_option_serverid[1 + 1 + 4]; /* option code, length byte, ip_addr */
 unsigned char vendor_option_requestedipaddr[1 + 1 + 4]; /* option code, length byte, ip_addr */
 
@@ -125,7 +125,7 @@ build_dhcp_packet(enum dhcp_flavor_t flavor)
 	packet->bootp_hlen = HLEN_ETHER;
 	packet->bootp_xid = BOOTP_XID;
 	packet->bootp_op = BOOTREQUEST;
-	bcopy(GetChaddr(), &packet->bootp_chaddr, sizeof(struct ether_addr));
+	bcopy(GetChaddr(), &packet->bootp_chaddr, sizeof(struct libnet_ether_addr));
 
 	/* add RFC1048 cookie to options field */
 	insert_option(&next_vendor_option, vendor_option_vm_cookie_rfc1048, sizeof(vendor_option_vm_cookie_rfc1048));
@@ -312,11 +312,11 @@ init_option_clientid(void)
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
