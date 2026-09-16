- libcdada >= 0.6.0 added a prev_val out-param to cdada_map_insert_replace()

--- src/nfv9_template.c.orig	2022-12-31 19:17:17 UTC
+++ src/nfv9_template.c
@@ -1628,7 +1628,7 @@ struct template_cache_entry *handle_template_v2(struct
   if (tpl_type == 0 || tpl_type == 2) {
     tpl = compose_template(hdr, (struct sockaddr *)pptrs->f_agent, tpl_type, sid, pens, version, len, seq);
 
-    ret = cdada_map_insert_replace(tpl_data_map, hash_keyval, tpl);
+    ret = cdada_map_insert_replace(tpl_data_map, hash_keyval, tpl, NULL);
     if (ret != CDADA_SUCCESS) {
       Log(LOG_WARNING, "WARN ( %s/core ): Unable to insert / refresh template in tpl_data_map\n", config.name);
       goto exit_lane;
@@ -1638,7 +1638,7 @@ struct template_cache_entry *handle_template_v2(struct
   else if (tpl_type == 1 || tpl_type == 3) {
     tpl = compose_opt_template(hdr, (struct sockaddr *)pptrs->f_agent, tpl_type, sid, pens, version, len, seq);
 
-    ret = cdada_map_insert_replace(tpl_data_map, hash_keyval, tpl);
+    ret = cdada_map_insert_replace(tpl_data_map, hash_keyval, tpl, NULL);
     if (ret != CDADA_SUCCESS) {
       Log(LOG_WARNING, "WARN ( %s/core ): Unable to insert / refresh template in tpl_opt_map\n", config.name);
       goto exit_lane;
