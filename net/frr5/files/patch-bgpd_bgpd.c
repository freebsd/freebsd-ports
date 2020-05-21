--- bgpd/bgpd.c.orig	2019-01-08 08:53:23 UTC
+++ bgpd/bgpd.c
@@ -243,7 +243,7 @@ static int bgp_router_id_set(struct bgp *bgp, const st
 
 	/* EVPN uses router id in RD, withdraw them */
 	if (is_evpn_enabled())
-		bgp_evpn_handle_router_id_update(bgp, TRUE);
+		bgp_evpn_handle_router_id_update(bgp, true);
 
 	IPV4_ADDR_COPY(&bgp->router_id, id);
 
@@ -260,7 +260,7 @@ static int bgp_router_id_set(struct bgp *bgp, const st
 
 	/* EVPN uses router id in RD, update them */
 	if (is_evpn_enabled())
-		bgp_evpn_handle_router_id_update(bgp, FALSE);
+		bgp_evpn_handle_router_id_update(bgp, false);
 
 	return 0;
 }
@@ -3098,7 +3098,7 @@ int bgp_handle_socket(struct bgp *bgp, struct vrf *vrf
 		/*
 		 * suppress vrf socket
 		 */
-		if (create == FALSE) {
+		if (create == false) {
 			bgp_close_vrf_socket(bgp);
 			return 0;
 		}
@@ -6861,8 +6861,8 @@ static void bgp_config_write_peer_global(struct vty *v
 	struct peer *g_peer = NULL;
 	char buf[SU_ADDRSTRLEN];
 	char *addr;
-	int if_pg_printed = FALSE;
-	int if_ras_printed = FALSE;
+	int if_pg_printed = false;
+	int if_ras_printed = false;
 
 	/* Skip dynamic neighbors. */
 	if (peer_dynamic_neighbor(peer))
@@ -6884,16 +6884,16 @@ static void bgp_config_write_peer_global(struct vty *v
 
 		if (peer_group_active(peer)) {
 			vty_out(vty, " peer-group %s", peer->group->name);
-			if_pg_printed = TRUE;
+			if_pg_printed = true;
 		} else if (peer->as_type == AS_SPECIFIED) {
 			vty_out(vty, " remote-as %u", peer->as);
-			if_ras_printed = TRUE;
+			if_ras_printed = true;
 		} else if (peer->as_type == AS_INTERNAL) {
 			vty_out(vty, " remote-as internal");
-			if_ras_printed = TRUE;
+			if_ras_printed = true;
 		} else if (peer->as_type == AS_EXTERNAL) {
 			vty_out(vty, " remote-as external");
-			if_ras_printed = TRUE;
+			if_ras_printed = true;
 		}
 
 		vty_out(vty, "\n");
