--- src/sfacctd.c.orig	2020-08-24 15:09:12 UTC
+++ src/sfacctd.c
@@ -50,7 +50,7 @@
 #endif
 
 /* variables to be exported away */
-struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
+extern struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
 int sfacctd_counter_backend_methods;
 struct bgp_misc_structs *sf_cnt_misc_db;
 struct host_addr debug_a;
