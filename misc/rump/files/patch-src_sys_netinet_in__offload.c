--- src/sys/netinet/in_offload.c.orig	2016-08-02 11:51:10 UTC
+++ src/sys/netinet/in_offload.c
@@ -210,9 +210,10 @@ ip_undefer_csum(struct mbuf *m, size_t h
 
 	if (__predict_true(hdrlen + sizeof(struct ip) <= m->m_len)) {
 		struct ip *ip = (struct ip *)(mtod(m, uint8_t *) + hdrlen);
+		short tmp = ip->ip_sum;
 
 		ip_len = ip->ip_len;
-		csump = &ip->ip_sum;
+		csump = &tmp;
 	} else {
 		const size_t ip_len_offset =
 		    hdrlen + offsetof(struct ip, ip_len);
