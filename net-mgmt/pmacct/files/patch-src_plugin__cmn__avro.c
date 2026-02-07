--- src/plugin_cmn_avro.c.orig	2022-12-31 19:17:17 UTC
+++ src/plugin_cmn_avro.c
@@ -1583,7 +1583,7 @@
     memset(&lbl, 0, sizeof(lbl));
     cdada_list_get(ll, idx_0, &lbl);
     /* handling label with value */
-    if (lbl.value) {
+    if (strlen(lbl.value) > 0) {
       if (avro_value_get_by_name(&v_type_record, "label", &v_type_union, NULL) == 0) {
         avro_value_set_branch(&v_type_union, TRUE, &v_type_branch);
         if (avro_value_add(&v_type_branch, lbl.key, &v_type_string, NULL, NULL) == 0) {
