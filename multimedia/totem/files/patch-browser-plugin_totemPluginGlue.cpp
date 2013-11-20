--- browser-plugin/totemPluginGlue.cpp.orig	2012-06-13 16:51:17.000000000 -0500
+++ browser-plugin/totemPluginGlue.cpp	2012-06-13 16:52:37.000000000 -0500
@@ -336,7 +336,7 @@
 	user_ini_file = g_build_filename (g_get_user_config_dir (),
 					  "totem",
 					  "browser-plugins.ini",
-					  NULL);
+					  (char *)NULL);
 	if (g_key_file_load_from_file (user,
 				       user_ini_file,
 				       G_KEY_FILE_NONE,
