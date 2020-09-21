--- src/client-agent/config.c.orig	2020-02-14 19:46:22 UTC
+++ src/client-agent/config.c
@@ -17,8 +17,8 @@
 time_t available_server;
 int run_foreground;
 keystore keys;
-agent *agt;
 
+extern agent *agt;
 
 /* Read the config file (for the remote client) */
 int ClientConf(const char *cfgfile)
