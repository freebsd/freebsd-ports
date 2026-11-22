--- bgpd/bgp_table.c.orig
+++ bgpd/bgp_table.c
@@ -242,52 +242,41 @@ void bgp_delete_listnode(struct bgp_dest *dest)
 	}
 }
 
-struct bgp_dest *bgp_table_subtree_lookup(const struct bgp_table *table,
-					  const struct prefix *p)
+struct route_node *bgp_table_subtree_lookup(const struct bgp_table *table, const struct prefix *p)
 {
-	struct bgp_dest *dest;
-	struct bgp_dest *matched = NULL;
+	struct route_node *node;
 
 	/* Unique-mode case is special; no iteration or prefix search */
-	if (route_table_is_unique_mode(table->route_table)) {
-		dest = bgp_node_lookup(table, p);
-		return dest;
-	}
+	if (route_table_is_unique_mode(table->route_table))
+		return route_node_lookup(table->route_table, p);
 
-	/* Search in LPM table */
-	dest = bgp_dest_from_rnode(table->route_table->top);
-	if (dest == NULL)
-		return NULL;
-
-	while (dest) {
-		const struct prefix *dest_p = bgp_dest_get_prefix(dest);
-		struct route_node *node = dest->rn;
-
-		if (dest_p->prefixlen >= p->prefixlen) {
-			if (!prefix_match(p, dest_p))
-				return NULL;
-
-			matched = dest;
-			break;
-		}
-
-		if (!prefix_match(dest_p, p))
+	/*
+	 * Search in LPM table. Walk route_nodes rather than bgp_dests: holder
+	 * nodes (rn->info == NULL) have no bgp_dest, but they are still part
+	 * of the path to the subtree, and may be the subtree root itself.
+	 */
+	node = table->route_table->top;
+	while (node) {
+		/* RD-keyed (VPN, ENCAP) and flowspec tables hold no IP prefixes */
+		if (node->p.family != p->family)
 			return NULL;
 
-		if (dest_p->prefixlen == p->prefixlen) {
-			matched = dest;
+		if (node->p.prefixlen >= p->prefixlen) {
+			if (!prefix_match(p, &node->p))
+				return NULL;
 			break;
 		}
 
-		dest = bgp_dest_from_rnode(
-			node->link[prefix_bit(&p->u.prefix, dest_p->prefixlen)]);
+		if (!prefix_match(&node->p, p))
+			return NULL;
+
+		node = node->link[prefix_bit(&p->u.prefix, node->p.prefixlen)];
 	}
 
-	if (!matched)
+	if (!node)
 		return NULL;
 
-	bgp_dest_lock_node(matched);
-	return matched;
+	return route_lock_node(node);
 }
 
 printfrr_ext_autoreg_p("BD", printfrr_bd);
