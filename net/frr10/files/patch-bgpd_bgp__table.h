--- bgpd/bgp_table.h.orig
+++ bgpd/bgp_table.h
@@ -327,13 +327,15 @@ static inline uint64_t bgp_table_version(struct bgp_table *table)
 
 /* Find the subtree of the prefix p
  *
- * This will return the first node that belongs the the subtree of p. Including
- * p itself, if it is in the tree.
+ * This will return the root route_node of the subtree of p, that is the first
+ * node in the table that is covered by p, including p itself. The returned node
+ * may be a holder node without a bgp_dest (rn->info == NULL); use
+ * bgp_dest_from_rnode() on it and on the nodes returned by route_next_until()
+ * to get the bgp_dests of the subtree. The returned node is locked.
  *
  * If the subtree is not present in the table, NULL is returned.
  */
-struct bgp_dest *bgp_table_subtree_lookup(const struct bgp_table *table,
-					  const struct prefix *p);
+struct route_node *bgp_table_subtree_lookup(const struct bgp_table *table, const struct prefix *p);
 
 static inline struct bgp_aggregate *
 bgp_dest_get_bgp_aggregate_info(struct bgp_dest *dest)
