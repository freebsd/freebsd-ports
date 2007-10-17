--- src/log.c.orig	Mon Oct 15 07:33:46 2007
+++ src/log.c	Mon Oct 15 07:33:46 2007
@@ -148,7 +148,8 @@
     g_free(log);
   }
   g_list_free(net?net->logs:other_logs);
-  net?net->logs:other_logs = NULL;
+  if (net) net->logs = NULL;
+  else other_logs = NULL;
 }
 
 void log_file_destroy(log_file_t* lf) {
