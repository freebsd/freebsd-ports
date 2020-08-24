--- src/pmbgpd.c.orig	2020-08-24 15:02:08 UTC
+++ src/pmbgpd.c
@@ -35,7 +35,7 @@
 #include "thread_pool.h"
 
 /* global var */
-struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
+extern struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
 
 /* Functions */
 void usage_daemon(char *prog_name)
