diff --git a/nest/proto.c b/nest/proto.c
index 60495aa..140ec94 100644
--- nest/proto.c
+++ nest/proto.c
@@ -376,6 +376,7 @@ int proto_reconfig_type;  /* Hack to propagate type info to pipe reconfigure hoo
 static int
 proto_reconfigure(struct proto *p, struct proto_config *oc, struct proto_config *nc, int type)
 {
+  struct announce_hook *ah = p->main_ahook;
   /* If the protocol is DOWN, we just restart it */
   if (p->proto_state == PS_DOWN)
     return 0;
@@ -407,14 +408,31 @@ proto_reconfigure(struct proto *p, struct proto_config *oc, struct proto_config
 
   /* Update filters and limits in the main announce hook
      Note that this also resets limit state */
-  if (p->main_ahook)
+  if (ah)
     {
-      p->main_ahook->in_filter = nc->in_filter;
-      p->main_ahook->out_filter = nc->out_filter;
-      p->main_ahook->rx_limit = nc->rx_limit;
-      p->main_ahook->in_limit = nc->in_limit;
-      p->main_ahook->out_limit = nc->out_limit;
-      p->main_ahook->in_keep_filtered = nc->in_keep_filtered;
+      ah->in_filter = nc->in_filter;
+      ah->out_filter = nc->out_filter;
+      ah->rx_limit = nc->rx_limit;
+      ah->in_limit = nc->in_limit;
+      ah->out_limit = nc->out_limit;
+      ah->in_keep_filtered = nc->in_keep_filtered;
+
+      if (p->proto_state == PS_UP)	/* Recheck export/import/receive limit */
+        {
+          struct proto_stats *stats = ah->stats;
+          struct proto_limit *l = ah->in_limit;
+          u32 all_routes = stats->imp_routes + stats->filt_routes;
+
+          if (l && (stats->imp_routes >= l->limit)) proto_notify_limit(ah, l, PLD_IN, stats->imp_routes);
+
+          l = ah->rx_limit;
+
+          if (l && ( all_routes >= l->limit)) proto_notify_limit(ah, l, PLD_RX, all_routes );
+
+          l = ah->out_limit;
+
+          if (l && ( stats->exp_routes >= l->limit)) proto_notify_limit(ah, l, PLD_OUT, stats->exp_routes);
+        }
     }
 
   /* Update routes when filters changed. If the protocol in not UP,
