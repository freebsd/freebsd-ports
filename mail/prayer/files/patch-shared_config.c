--- shared/config.c.orig	2012-06-30 14:30:08 UTC
+++ shared/config.c
@@ -455,9 +455,9 @@ static struct {
     "draft_att_total_max", config_number, OFFSET(draft_att_total_max)}
     , {
     "dualuse", config_bool, OFFSET(dualuse)}
-    , {
+    , /*{
     "egd_socket", config_path, OFFSET(egd_socket)}
-    , {
+    , */{
     "expunge_on_exit", config_bool, OFFSET(expunge_on_exit)}
     , {
     "fatal_dump_core", config_bool, OFFSET(fatal_dump_core)}
