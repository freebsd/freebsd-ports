--- src/pmbmpd.c.orig	2020-08-24 14:59:55 UTC
+++ src/pmbmpd.c
@@ -33,7 +33,7 @@
 #include "net_aggr.h"
 
 /* global var */
-struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
+extern struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
 
 /* Functions */
 void usage_daemon(char *prog_name)
