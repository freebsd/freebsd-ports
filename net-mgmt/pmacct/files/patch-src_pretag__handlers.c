--- src/pretag_handlers.c.orig	2022-12-31 19:17:17 UTC
+++ src/pretag_handlers.c
@@ -4231,6 +4231,7 @@ int PT_map_index_fdata_src_net_handler(struct id_table
   else return TRUE;
 
   if (idx_netmask >= 0 && idx->netmask.hdlr_no == (idx_hdlr + 1)) {
+    ret=-1;
     if (e->key.src_net.a.family == AF_INET) {
       ret = cdada_list_get(idx->netmask.v4.list, idx_netmask, &netmask);
     }
@@ -4301,6 +4302,7 @@ int PT_map_index_fdata_dst_net_handler(struct id_table
   else return TRUE;
 
   if (idx_netmask >= 0 && idx->netmask.hdlr_no == (idx_hdlr + 1)) {
+    ret=-1;
     if (e->key.dst_net.a.family == AF_INET) {
       ret = cdada_list_get(idx->netmask.v4.list, idx_netmask, &netmask);
     }
