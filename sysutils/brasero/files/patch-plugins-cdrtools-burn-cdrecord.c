--- plugins/cdrtools/burn-cdrecord.c.orig	2010-08-19 21:55:26.000000000 +0000
+++ plugins/cdrtools/burn-cdrecord.c	2010-08-19 21:55:50.000000000 +0000
@@ -1442,6 +1442,6 @@
 	brasero_plugin_test_app (plugin,
 	                         "cdrecord",
 	                         "--version",
-	                         "Cdrecord-ProDVD-ProBD-Clone %d.%d",
+	                         "Cdrecord-Clone %d.%d",
 	                         version);
 }
