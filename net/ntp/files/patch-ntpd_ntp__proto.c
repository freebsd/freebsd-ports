--- ntpd/ntp_proto.c.orig	2024-05-07 04:21:28.000000000 -0700
+++ ntpd/ntp_proto.c	2025-02-18 19:48:02.135233000 -0800
@@ -474,7 +474,7 @@
 	/* [Bug 3851] drop pool servers which can no longer be reached. */
 	if (MDF_PCLNT & peer->cast_flags) {
 		if (   (IS_IPV6(&peer->srcadr) && !nonlocal_v6_addr_up)
-		    || !nonlocal_v4_addr_up) {
+		    || (IS_IPV4(&peer->srcadr) && !nonlocal_v4_addr_up)) {
 			unpeer(peer);
 			return;
 		}
