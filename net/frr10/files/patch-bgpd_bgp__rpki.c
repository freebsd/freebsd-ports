--- bgpd/bgp_rpki.c.orig
+++ bgpd/bgp_rpki.c
@@ -59,6 +59,7 @@ DEFINE_MTYPE_STATIC(BGPD, BGP_RPKI_REVALIDATE, "BGP RPKI Revalidation");
 #define EXPIRE_INTERVAL_DEFAULT 7200
 #define RETRY_INTERVAL_DEFAULT 600
 #define BGP_RPKI_CACHE_SERVER_SYNC_RETRY_TIMEOUT 3
+#define RPKI_REVALIDATE_ALL_DELAY_MSEC 500
 
 #define RPKI_DEBUG(...)                                                        \
 	if (rpki_debug_conf || rpki_debug_term) {                              \
@@ -108,6 +109,7 @@ struct rpki_vrf {
 	int rpki_sync_socket_bgpd;
 	char *vrfname;
 	struct event *t_rpki_sync;
+	struct event *t_revalidate_all;
 
 	QOBJ_FIELDS;
 };
@@ -156,6 +158,7 @@ static enum route_map_cmd_result_t route_match(void *rule,
 					       void *object);
 static void *route_match_compile(const char *arg);
 static void revalidate_bgp_node(struct bgp *bgp, struct bgp_dest *dest, afi_t afi, safi_t safi);
+static void rpki_revalidate_all(struct event *event);
 static struct rpki_vrf *get_rpki_vrf(const char *vrfname);
 
 static bool rpki_debug_conf, rpki_debug_term;
@@ -602,19 +605,22 @@ struct rpki_revalidate_prefix {
 static void rpki_revalidate_prefix(struct event *event)
 {
 	struct rpki_revalidate_prefix *rrp = EVENT_ARG(event);
-	struct bgp_dest *match, *node;
+	struct route_node *match, *rn;
+	struct bgp_dest *dest;
 
 	match = bgp_table_subtree_lookup(rrp->bgp->rib[rrp->afi][rrp->safi],
 					 &rrp->prefix);
 
-	node = match;
-
-	while (node) {
-		if (bgp_dest_has_bgp_path_info_data(node)) {
-			revalidate_bgp_node(rrp->bgp, node, rrp->afi, rrp->safi);
-		}
-
-		node = bgp_route_next_until(node, match);
+	/*
+	 * The subtree root may be a holder node without a bgp_dest, so walk
+	 * the route_nodes. Revalidate destinations that only have Adj-RIB-In
+	 * entries too: a path denied by inbound policy has no path info, and
+	 * must be re-evaluated in case it is no longer denied.
+	 */
+	for (rn = match; rn; rn = route_next_until(rn, match)) {
+		dest = bgp_dest_from_rnode(rn);
+		if (dest && (bgp_dest_has_bgp_path_info_data(dest) || dest->adj_in))
+			revalidate_bgp_node(rrp->bgp, dest, rrp->afi, rrp->safi);
 	}
 
 	XFREE(MTYPE_BGP_RPKI_REVALIDATE, rrp);
@@ -675,23 +681,25 @@ static void bgpd_sync_callback(struct event *event)
 	if (atomic_load_explicit(&rpki_vrf->rtr_update_overflow, memory_order_seq_cst)) {
 		ssize_t size = 0;
 
-		retval = read(rpki_vrf->rpki_sync_socket_bgpd, &rec, sizeof(struct pfx_record));
-		while (retval != -1) {
-			if (retval != sizeof(struct pfx_record))
-				break;
-
+		while ((retval = read(rpki_vrf->rpki_sync_socket_bgpd, &rec,
+				      sizeof(struct pfx_record))) > 0)
 			size += retval;
-			pfx_record_to_prefix(&rec, &prefix);
-			afi = (rec.prefix.ver == LRTR_IPV4) ? AFI_IP : AFI_IP6;
-			revalidate_single_prefix(vrf, prefix, afi);
-
-			retval = read(rpki_vrf->rpki_sync_socket_bgpd, &rec,
-				      sizeof(struct pfx_record));
-		}
-
-		RPKI_DEBUG("Socket overflow detected (%zu), revalidating affected prefixes", size);
 
 		atomic_store_explicit(&rpki_vrf->rtr_update_overflow, 0, memory_order_seq_cst);
+
+		/*
+		 * While the socket was full, the records that did not fit were
+		 * dropped, so revalidating the drained ones is not enough: they
+		 * may be a small part of the update. Revalidate all routes
+		 * instead, unless the initial sync is still running, which ends
+		 * with a full revalidation anyway. The timer coalesces the
+		 * overflows of one burst.
+		 */
+		RPKI_DEBUG("Socket overflow detected (%zd), revalidating all routes", size);
+		if (is_synchronized(rpki_vrf))
+			event_add_timer_msec(bm->master, rpki_revalidate_all, rpki_vrf,
+					     RPKI_REVALIDATE_ALL_DELAY_MSEC,
+					     &rpki_vrf->t_revalidate_all);
 		return;
 	}
 
@@ -707,35 +715,24 @@ static void bgpd_sync_callback(struct event *event)
 	revalidate_single_prefix(vrf, prefix, afi);
 }
 
-static void revalidate_bgp_node(struct bgp *bgp, struct bgp_dest *bgp_dest, afi_t afi, safi_t safi)
+/*
+ * Locally originated routes (e.g., 'network' statement) have no adj_in
+ * entry, so neither bgp_update() of the Adj-RIB-In nor a soft inbound
+ * reconfiguration covers them.  Force re-advertisement so the outbound
+ * route-map re-evaluates the updated RPKI state.
+ * If we have something like:
+ * route-map out deny 10
+ *   match rpki invalid
+ * route-map out permit 20
+ * Then a locally originated route that becomes RPKI invalid needs to be
+ * re-evaluated against the route-map, and if we don't force
+ * re-advertisement, it won't be.
+ */
+static void revalidate_local_routes(struct bgp *bgp, struct bgp_dest *bgp_dest, afi_t afi,
+				    safi_t safi)
 {
-	struct bgp_adj_in *ain;
 	struct bgp_path_info *bpi;
-	mpls_label_t *label;
-	uint8_t num_labels;
 
-	for (ain = bgp_dest->adj_in; ain; ain = ain->next) {
-		struct bgp_path_info *path = bgp_dest_get_bgp_path_info(bgp_dest);
-
-		num_labels = BGP_PATH_INFO_NUM_LABELS(path);
-		label = num_labels ? path->extra->labels->label : NULL;
-
-		(void)bgp_update(ain->peer, bgp_dest_get_prefix(bgp_dest), ain->addpath_rx_id,
-				 ain->attr, afi, safi, ZEBRA_ROUTE_BGP, BGP_ROUTE_NORMAL, NULL,
-				 label, num_labels, 1, NULL);
-	}
-
-	/* Locally originated routes (e.g., 'network' statement) have no adj_in
-	 * entry, so bgp_update() above won't cover them.  Force re-advertisement
-	 * so the outbound route-map re-evaluates the updated RPKI state.
-	 * If we have something like:
-	 * route-map out deny 10
-	 *   match rpki invalid
-	 * route-map out permit 20
-	 * Then a locally originated route that becomes RPKI invalid needs to be
-	 * re-evaluated against the route-map, and if we don't force
-	 * re-advertisement, it won't be.
-	 */
 	for (bpi = bgp_dest_get_bgp_path_info(bgp_dest); bpi; bpi = bpi->next) {
 		if (bpi->peer == bgp->peer_self && bpi->type == ZEBRA_ROUTE_BGP &&
 		    (bpi->sub_type == BGP_ROUTE_STATIC || bpi->sub_type == BGP_ROUTE_AGGREGATE)) {
@@ -746,6 +743,25 @@ static void revalidate_bgp_node(struct bgp *bgp, struct bgp_dest *bgp_dest, afi_
 	}
 }
 
+static void revalidate_bgp_node(struct bgp *bgp, struct bgp_dest *bgp_dest, afi_t afi, safi_t safi)
+{
+	struct bgp_adj_in *ain;
+	mpls_label_t *label;
+	uint8_t num_labels;
+
+	for (ain = bgp_dest->adj_in; ain; ain = ain->next) {
+		/* There may be no path info if the route was denied */
+		num_labels = ain->labels ? ain->labels->num_labels : 0;
+		label = num_labels ? &ain->labels->label[0] : NULL;
+
+		(void)bgp_update(ain->peer, bgp_dest_get_prefix(bgp_dest), ain->addpath_rx_id,
+				 ain->attr, afi, safi, ZEBRA_ROUTE_BGP, BGP_ROUTE_NORMAL, NULL,
+				 label, num_labels, 1, NULL);
+	}
+
+	revalidate_local_routes(bgp, bgp_dest, afi, safi);
+}
+
 static void rpki_update_cb_sync_rtr(struct pfx_table *p __attribute__((unused)),
 				    const struct pfx_record rec,
 				    const bool added __attribute__((unused)))
@@ -792,6 +808,63 @@ err:
 	flog_err(EC_LIB_DEVELOPMENT, "RPKI: %s", msg);
 }
 
+/*
+ * Re-run the inbound policy of every peer with soft-reconfiguration inbound,
+ * and re-advertise the locally originated routes, for the bgp instance(s)
+ * that use this RPKI configuration.
+ */
+static void revalidate_all_routes(struct rpki_vrf *rpki_vrf)
+{
+	struct listnode *node, *pnode;
+	struct vrf *vrf = NULL;
+	struct peer *peer;
+	struct bgp *bgp;
+	afi_t afi;
+	safi_t safi;
+
+	if (rpki_vrf->vrfname) {
+		vrf = vrf_lookup_by_name(rpki_vrf->vrfname);
+		if (!vrf)
+			return;
+	}
+
+	for (ALL_LIST_ELEMENTS_RO(bm->bgp, node, bgp)) {
+		if (!vrf && bgp->vrf_id != VRF_DEFAULT)
+			continue;
+		if (vrf && bgp->vrf_id != vrf->vrf_id)
+			continue;
+
+		for (ALL_LIST_ELEMENTS_RO(bgp->peer, pnode, peer)) {
+			FOREACH_AFI_SAFI (afi, safi)
+				bgp_soft_reconfig_in(peer, afi, safi);
+		}
+
+		/*
+		 * The soft reconfiguration only replays the Adj-RIB-In. Walk the
+		 * tables that RPKI validates for the locally originated routes,
+		 * as rpki_revalidate_prefix() does for the routes of one VRP.
+		 */
+		FOREACH_AFI_SAFI (afi, safi) {
+			struct bgp_table *table = bgp->rib[afi][safi];
+			struct bgp_dest *dest;
+
+			if (!table || (safi != SAFI_UNICAST && safi != SAFI_MULTICAST &&
+				       safi != SAFI_LABELED_UNICAST))
+				continue;
+
+			for (dest = bgp_table_top(table); dest; dest = bgp_route_next(dest)) {
+				if (bgp_dest_has_bgp_path_info_data(dest))
+					revalidate_local_routes(bgp, dest, afi, safi);
+			}
+		}
+	}
+}
+
+static void rpki_revalidate_all(struct event *event)
+{
+	revalidate_all_routes(EVENT_ARG(event));
+}
+
 static void rpki_init_sync_socket(struct rpki_vrf *rpki_vrf)
 {
 	int fds[2];
@@ -916,6 +989,14 @@ static void sync_expired(struct event *event)
 	RPKI_DEBUG("rtr_mgr sync is done.");
 
 	rpki_vrf->rtr_is_synced = true;
+
+	/*
+	 * Until now the validation state of every route was "not used", also
+	 * when the VRPs of the initial sync were revalidated one by one, so
+	 * routes that are invalid may have been accepted. Re-run the inbound
+	 * policy now that the VRP set is complete.
+	 */
+	revalidate_all_routes(rpki_vrf);
 }
 
 static int start(struct rpki_vrf *rpki_vrf)
@@ -985,6 +1066,7 @@ static void stop(struct rpki_vrf *rpki_vrf)
 	rpki_vrf->rtr_is_stopping = true;
 	if (is_running(rpki_vrf)) {
 		event_cancel(&rpki_vrf->t_rpki_sync);
+		event_cancel(&rpki_vrf->t_revalidate_all);
 
 		for (ALL_LIST_ELEMENTS_RO(rpki_vrf->cache_list, cache_node, cache))
 			frr_pthread_non_controlled_shutdown(cache->rtr_socket->thread_id);
