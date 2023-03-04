--- src/bgp/bgp_lookup.c.orig	2022-12-31 19:17:17 UTC
+++ src/bgp/bgp_lookup.c
@@ -349,7 +349,7 @@
   struct in6_addr pref6;
   u_char *saved_agent = pptrs->f_agent;
   pm_id_t bta;
-  u_int32_t modulo, local_modulo, modulo_idx, modulo_max;
+  u_int32_t modulo, modulo_idx, modulo_max;
 
   bms = bgp_select_misc_db(type);
   inter_domain_routing_db = bgp_select_routing_db(type);
@@ -421,7 +421,7 @@
 
     // XXX: to be optimized
     if (result_node) {
-      for (local_modulo = modulo, modulo_idx = 0; modulo_idx < modulo_max; local_modulo++, modulo_idx++) {
+      for (modulo_idx = 0; modulo_idx < modulo_max; modulo_idx++) {
         for (info = result_node->info[modulo]; info; info = info->next) {
           if (info->peer == nh_peer) break;
 	}
