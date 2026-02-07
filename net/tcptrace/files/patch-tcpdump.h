--- tcpdump.h.orig	2013-07-01 18:43:14 UTC
+++ tcpdump.h
@@ -179,7 +179,7 @@ static int find_ip_fddi(char* buf, int iplen) {
 }
 
 /* This function determine the offset for the IP packet in an Ethernet frame */
-/* We handle two cases : straight Ethernet encapsulation or PPPoE encapsulation */
+/* We handle three cases : straight Ethernet, PPPoE, or .1q VLAN encapsulation */
 /* Written by Yann Samama (ysamama@nortelnetworks.com) on july 18th, 2003 */
 static int find_ip_eth(char* buf)
 {
@@ -192,16 +192,19 @@ static int find_ip_eth(char* buf)
 	switch (eth_proto_type)
 	{
 		case ETHERTYPE_IPV6: /* it's pure IPv6 over ethernet */
-			offset = 14;
-			break;
+			/* FALLTHROUGH */
 		case ETHERTYPE_IP: /* it's pure IPv4 over ethernet */
-			offset = 14;
+			offset = sizeof(struct ether_header);
 			break;
 		case ETHERTYPE_PPPOE_SESSION: /* it's a PPPoE session */
 			memcpy(&ppp_proto_type, buf+20, 2);
 			ppp_proto_type = ntohs(ppp_proto_type);
 			if (ppp_proto_type == 0x0021) /* it's IP over PPPoE */
 				offset = PPPOE_SIZE;
+			break;
+		case ETHERTYPE_VLAN:
+			offset = sizeof(struct ether_header) +
+			    ETHER_VLAN_ENCAP_LEN;
 			break;
 		default: /* well, this is not an IP packet */
 			offset = -1;
