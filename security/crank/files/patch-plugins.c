--- plugins.c.orig	Mon Apr 23 14:14:51 2001
+++ plugins.c	Mon Apr 23 14:16:13 2001
@@ -61,7 +61,7 @@
 	g_warning("Plugins not supported on this platform.");
 	return;
     }
-    if (!(plugin_dir = opendir("plugins"))) {
+    if (!(plugin_dir = opendir(PLUGIN_DIR))) {
 	g_warning("Could not open plugin directory - %s", PLUGIN_DIR);
 	return;
     }
