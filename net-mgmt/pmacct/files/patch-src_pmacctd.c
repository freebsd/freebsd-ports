--- src/pmacctd.c.orig	2020-08-24 15:11:03 UTC
+++ src/pmacctd.c
@@ -41,7 +41,7 @@
 #include "jhash.h"
 
 /* variables to be exported away */
-struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
+extern struct channels_list_entry channels_list[MAX_N_PLUGINS]; /* communication channels: core <-> plugins */
 
 /* Functions */
 void usage_daemon(char *prog_name)
