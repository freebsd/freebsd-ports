Index: src/pppoe.c
===================================================================
--- src/pppoe.c	(revision 2420)
+++ src/pppoe.c	(revision 2423)
@@ -1257,6 +1257,8 @@ PppoeListenEvent(int type, void *arg)
 	const struct pppoe_hdr	*ph;
 	const struct pppoe_tag  *tag;
 
+	u_int16_t		length;
+
 	union {
 	    u_char buf[sizeof(struct ngpppoe_init_data) + MAX_SESSION];
 	    struct ngpppoe_init_data poeid;
@@ -1288,6 +1290,20 @@ PppoeListenEvent(int type, void *arg)
 
 	wh = (struct pppoe_full_hdr *)response;
 	ph = &wh->ph;
+
+	/* Sanity check */
+	length = ntohs(ph->length);
+	if (length > (size_t)sz - sizeof(struct pppoe_full_hdr)) {
+		Log(LG_PHYS, ("Ignored incoming PPPoE connection request "
+		    "via %s for service \"%s\" from %s "
+		    "due to bad length %hu > %u",
+		    PIf->ifnodepath, session,
+		    ether_ntoa((const struct ether_addr *)&wh->eh.ether_shost),
+		    length,
+		    (unsigned)((size_t)sz - sizeof(struct pppoe_full_hdr))));
+		return;
+	}
+
 	if ((tag = get_tag(ph, PTT_SRV_NAME))) {
 	    size_t len = ntohs(tag->tag_len);
 	    if (len >= sizeof(real_session))
