--- ospfd/packet.c.orig	9 Mar 2006 13:31:57 -0000	1.20
+++ ospfd/packet.c	16 Mar 2006 18:21:38 -0000
@@ -34,7 +34,7 @@
 #include "log.h"
 #include "ospfe.h"
 
-int		 ip_hdr_sanity_check(const struct ip *, u_int16_t);
+int		 ip_hdr_sanity_check(struct ip *, u_int16_t);
 int		 ospf_hdr_sanity_check(const struct ip *,
 		    struct ospf_hdr *, u_int16_t, const struct iface *);
 struct iface	*find_iface(struct ospfd_conf *, struct in_addr);
@@ -196,8 +196,13 @@ recv_packet(int fd, short event, void *b
 }
 
 int
-ip_hdr_sanity_check(const struct ip *ip_hdr, u_int16_t len)
+ip_hdr_sanity_check(struct ip *ip_hdr, u_int16_t len)
 {
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+	/* FreeBSD and NetBSD modify the IP header. Undo it! */
+	ip_hdr->ip_len = htons(ip_hdr->ip_len + (ip_hdr->ip_hl << 2));
+#endif
+
 	if (ntohs(ip_hdr->ip_len) != len) {
 		log_debug("recv_packet: invalid IP packet length %u",
 		    ntohs(ip_hdr->ip_len));
