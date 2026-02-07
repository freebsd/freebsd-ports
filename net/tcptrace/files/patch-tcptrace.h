--- tcptrace.h.orig	2013-07-01 18:43:14 UTC
+++ tcptrace.h
@@ -1188,6 +1188,10 @@ struct ipaddr *IPV6ADDR2ADDR(struct in6_addr *addr6);
 #define ETHERTYPE_VLAN		0x8100
 #endif	/* 802.1Q Virtual LAN */
 
+#ifndef ETHER_VLAN_ENCAP_LEN
+#define ETHER_VLAN_ENCAP_LEN	4
+#endif /* 802.1Q tag header length */
+
 /* support for PPPoE encapsulation added by Yann Samama (ysamama@nortelnetworks.com)*/
 #ifndef ETHERTYPE_PPPOE_SESSION
 #define ETHERTYPE_PPPOE_SESSION	0x8864
