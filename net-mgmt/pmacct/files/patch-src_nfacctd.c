--- src/nfacctd.c.orig	2020-08-24 15:07:56 UTC
+++ src/nfacctd.c
@@ -49,7 +49,7 @@ struct template_cache tpl_cache;
 struct host_addr debug_a;
 char debug_agent_addr[50];
 u_int16_t debug_agent_port;
-struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
+extern struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
 
 /* Functions */
 void usage_daemon(char *prog_name)
