--- plugins.c.orig	Thu Apr 19 03:34:39 2001
+++ plugins.c	Thu Apr 19 03:35:01 2001
@@ -60,7 +60,7 @@
     if (!g_module_supported())
 	g_error("Plugins not supported on this platform.");
 
-    if (!(plugin_dir = opendir("plugins")))
+    if (!(plugin_dir = opendir(PLUGIN_DIR)))
 	g_error("Could not open plugin directory - %s", PLUGIN_DIR);
 
     /* Loop over each file in the plugin directory */
