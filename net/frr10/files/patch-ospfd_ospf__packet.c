--- ospfd/ospf_packet.c.orig	2026-07-15 15:51:52 UTC
+++ ospfd/ospf_packet.c
@@ -3244,9 +3244,18 @@ static int ospf_make_hello(struct ospf_interface *oi, 
 	/* Set netmask of interface. */
 	if (!(CHECK_FLAG(oi->connected->flags, ZEBRA_IFA_UNNUMBERED)
 	      && oi->type == OSPF_IFTYPE_POINTOPOINT)
-	    && oi->type != OSPF_IFTYPE_VIRTUALLINK)
-		masklen2ip(oi->address->prefixlen, &mask);
-	else
+	    && oi->type != OSPF_IFTYPE_VIRTUALLINK) {
+		/* For a peer-addressed interface (FreeBSD gif/gre/vti tunnels)
+		 * the local address is /32; the real subnet prefixlen lives on
+		 * the peer. Use that one so strict OSPF peers (RouterOS, IOS,
+		 * Junos) don't see a /32 mask on a numbered link.
+		 */
+		if (CONNECTED_PEER(oi->connected))
+			masklen2ip(oi->connected->destination->prefixlen,
+				   &mask);
+		else
+			masklen2ip(oi->address->prefixlen, &mask);
+	} else
 		memset((char *)&mask, 0, sizeof(struct in_addr));
 	stream_put_ipv4(s, mask.s_addr);
 
