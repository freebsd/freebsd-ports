Index: src/plugins.c
diff -u -p src/plugins.c.orig src/plugins.c
--- src/plugins.c.orig	Sun Jun 23 04:08:41 2002
+++ src/plugins.c	Tue Nov 23 01:39:49 2004
@@ -794,6 +794,11 @@ install_plugin(gchar *plugin_name)
 		plugin_log(buf, NULL);
 		return NULL;
 		}
+	/*
+	 * Reset dlerror() since it can contain error from previous
+	 * call to dlopen()/dlsym().
+	 */
+	dlerror();
 	init_plugin = dlsym(handle, "init_plugin");
 	if ((error = dlerror()) != NULL)
 		{
