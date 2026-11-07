Keep filtered routes out of the best export on next-hop autoupdate.

--- nest/rt-table.c.orig	2026-10-20 20:35:04 UTC
+++ nest/rt-table.c
@@ -4824,9 +4824,13 @@ rt_next_hop_update_net(struct rtable_private *tab, str
     }
   ASSERT_DIE(~nbpos);
 
+  /* No invalid routes allowed in the best export */
+  const rte *new_best_valid = RTE_VALID_OR_NULL(&new_best->rte);
+  const rte *old_best_valid = RTE_VALID_OR_NULL(&old_best->rte);
+
   struct rt_pending_export *best_rpe =
     (new_best != old_best) ?
-    rte_announce_to(&tab->export_best, &n->best, &new_best->rte, &old_best->rte)
+    rte_announce_to(&tab->export_best, &n->best, new_best_valid, old_best_valid)
     : NULL;
 
   uint total = 0;
@@ -4852,7 +4856,7 @@ rt_next_hop_update_net(struct rtable_private *tab, str
     rt_rte_trace_in(D_ROUTES, updates[i].new.sender->req, &updates[i].new, info);
 
     /* Double announcement of this specific route */
-    if (ob && best_rpe)
+    if (ob && best_rpe && best_rpe->it.old)
     {
       ASSERT_DIE(best_rpe->it.old == &updates[i].old->rte);
       ASSERT_DIE(!best_rpe->seq_all);
@@ -4866,7 +4870,7 @@ rt_next_hop_update_net(struct rtable_private *tab, str
 
   if (best_rpe && !best_rpe->seq_all)
   {
-    ASSERT_DIE(!updates[0].new_stored);
+    ASSERT_DIE(!updates[0].new_stored || !best_rpe->it.old);
     best_rpe->seq_all = last_seq;
   }
 
