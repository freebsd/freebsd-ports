--- src/net_aggr.h.orig	2022-12-31 19:17:17 UTC
+++ src/net_aggr.h
@@ -91,7 +91,7 @@ typedef void (*net_func) (struct networks_table *, str
 typedef void (*net_func) (struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *);
 
 /* prototypes */
-extern void set_net_funcs();
+extern void set_net_funcs(struct networks_table *);
 extern void init_net_funcs(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *); 
 extern void mask_src_ipaddr(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *); 
 extern void mask_dst_ipaddr(struct networks_table *, struct networks_cache *, struct pkt_primitives *, struct pkt_bgp_primitives *, struct networks_file_data *); 
