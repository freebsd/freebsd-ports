--- ospfd/packet.c.orig	2006-11-17 11:55:31.000000000 +0300
+++ ospfd/packet.c	2008-02-13 22:13:04.000000000 +0300
@@ -36,7 +36,7 @@
 #include "log.h"
 #include "ospfe.h"
 
-int		 ip_hdr_sanity_check(const struct ip *, u_int16_t);
+int		 ip_hdr_sanity_check(struct ip *, u_int16_t);
 int		 ospf_hdr_sanity_check(const struct ip *,
 		    struct ospf_hdr *, u_int16_t, const struct iface *);
 struct iface	*find_iface(struct ospfd_conf *, unsigned int, struct in_addr);
@@ -70,7 +70,12 @@
 	ip_hdr.ip_v = IPVERSION;
 	ip_hdr.ip_hl = sizeof(ip_hdr) >> 2;
 	ip_hdr.ip_tos = IPTOS_PREC_INTERNETCONTROL;
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+	/* FreeBSD/NetBSD wants the length in the native host byte order. */
+	ip_hdr.ip_len = len + sizeof(ip_hdr);
+#else
 	ip_hdr.ip_len = htons(len + sizeof(ip_hdr));
+#endif
 	ip_hdr.ip_id = 0;  /* 0 means kernel set appropriate value */
 	ip_hdr.ip_off = 0;
 	ip_hdr.ip_ttl = iface->type != IF_TYPE_VIRTUALLINK ?
@@ -248,8 +253,13 @@
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
