--- src/interfaces.h.orig	2024-08-15 16:06:02 UTC
+++ src/interfaces.h
@@ -25,6 +25,7 @@ struct net_interface {
 	char name[256];
 	unsigned char ipv4_addr[IPV4_ALEN];
 	unsigned char mac_addr[ETH_ALEN];
+	unsigned char bcast_addr[IPV4_ALEN];
 
 	/* used by mactelnetd */
 	int socketfd;
@@ -57,4 +58,4 @@ extern int net_send_udp(const int socket, struct net_i
 						const unsigned char *destmac, const struct in_addr *sourceip, const int sourceport,
 						const struct in_addr *destip, const int destport, const unsigned char *data, const int datalen);
 extern unsigned short in_cksum(unsigned short *addr, int len);
-#endif
\ No newline at end of file
+#endif
