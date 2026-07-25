--- zebra/connected.c.orig	2026-05-30 23:00:53 UTC
+++ zebra/connected.c
@@ -60,7 +60,10 @@ static void connected_announce(struct interface *ifp, 
 		return;
 
 	if (!if_is_loopback(ifp) && ifc->address->family == AF_INET) {
-		if (ifc->address->prefixlen == IPV4_MAX_BITLEN)
+		struct prefix *p = CONNECTED_PEER(ifc) ? ifc->destination
+						       : ifc->address;
+
+		if (p->prefixlen == IPV4_MAX_BITLEN)
 			SET_FLAG(ifc->flags, ZEBRA_IFA_UNNUMBERED);
 		else
 			UNSET_FLAG(ifc->flags, ZEBRA_IFA_UNNUMBERED);
