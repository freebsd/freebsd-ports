Index: tunip.c
===================================================================
--- tunip.c	(revision 35)
+++ tunip.c	(working copy)
@@ -596,10 +596,6 @@
 	/* Fill non-mutable fields */
 	ip->ip_v = IPVERSION;
 	ip->ip_hl = 5;
-	ip->ip_len = encap->buflen + (peer->remote_sa->md_algo? 12 :0);
-#ifdef NEED_IPLEN_FIX
-	ip->ip_len = htons(ip->ip_len);
-#endif
 	/*gcry_md_get_algo_dlen(md_algo); see RFC .. only use 96 bit */
 	ip->ip_id = htons(ip_id++);
 	ip->ip_p = IPPROTO_ESP;
@@ -614,6 +610,10 @@
 
 	encap_esp_encapsulate(encap, peer);
 
+	ip->ip_len = encap->buflen;
+#ifdef NEED_IPLEN_FIX
+	ip->ip_len = htons(ip->ip_len);
+#endif
 	ip->ip_sum = in_cksum((u_short *) encap->buf, sizeof(struct ip));
 
 	sent = sendto(encap->fd, encap->buf, encap->buflen, 0,
