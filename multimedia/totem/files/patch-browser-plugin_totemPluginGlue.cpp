--- browser-plugin/totemPluginGlue.cpp.orig	2008-03-15 18:00:23.000000000 -0500
+++ browser-plugin/totemPluginGlue.cpp	2008-03-15 18:01:54.000000000 -0500
@@ -356,7 +356,7 @@
 	user_ini_file = g_build_filename (g_get_user_config_dir (),
 					  "totem",
 					  "browser-plugins.ini",
-					  NULL);
+					  (char *)NULL);
 	if (g_key_file_load_from_file (user,
 				       user_ini_file,
 				       G_KEY_FILE_NONE,
@@ -439,7 +439,7 @@
 	/* we want to open libdbus-glib-1.so.2 in such a way
 	 * in such a way that it becomes permanentely resident */
 	void *handle;
-	handle = dlopen ("libdbus-glib-1.so.2", RTLD_NOW | RTLD_NODELETE);
+	handle = dlopen ("libdbus-glib-1.so.2", RTLD_NOW);
 	if (!handle) {
 		fprintf (stderr, "%s\n", dlerror()); 
 		return NPERR_MODULE_LOAD_FAILED_ERROR;
