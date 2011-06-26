--- proto/bgp/packets.c
+++ proto/bgp/packets.c
@@ -862,7 +862,7 @@ bgp_do_rx_update(struct bgp_conn *conn,
   if (conn->state != BS_ESTABLISHED)	/* fatal error during decoding */
     return;
 
-  if (a0 && bgp_set_next_hop(p, a0))
+  if (a0 && nlri_len && bgp_set_next_hop(p, a0))
     a = rta_lookup(a0);
 
   while (nlri_len)
