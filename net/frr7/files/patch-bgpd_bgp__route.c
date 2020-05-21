--- bgpd/bgp_route.c.orig	2020-02-14 14:03:09 UTC
+++ bgpd/bgp_route.c
@@ -9922,7 +9922,7 @@ static int bgp_show_route_in_table(struct vty *vty, st
 		}
 	} else if (safi == SAFI_EVPN) {
 		struct bgp_node *longest_pfx;
-		bool is_exact_pfxlen_match = FALSE;
+		bool is_exact_pfxlen_match = false;
 
 		for (rn = bgp_table_top(rib); rn; rn = bgp_route_next(rn)) {
 			if (prd && memcmp(rn->p.u.val, prd->val, 8) != 0)
@@ -9932,7 +9932,7 @@ static int bgp_show_route_in_table(struct vty *vty, st
 				continue;
 
 			longest_pfx = NULL;
-			is_exact_pfxlen_match = FALSE;
+			is_exact_pfxlen_match = false;
 			/*
 			 * Search through all the prefixes for a match.  The
 			 * pfx's are enumerated in ascending order of pfxlens.
@@ -9951,7 +9951,7 @@ static int bgp_show_route_in_table(struct vty *vty, st
 					int type5_pfxlen =
 					   bgp_evpn_get_type5_prefixlen(&rm->p);
 					if (type5_pfxlen == match.prefixlen) {
-						is_exact_pfxlen_match = TRUE;
+						is_exact_pfxlen_match = true;
 						bgp_unlock_node(rm);
 						break;
 					}
