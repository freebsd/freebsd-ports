--- src/plugin.c.orig	2007-07-14 19:40:48.000000000 +0000
+++ src/plugin.c	2007-07-14 19:43:00.000000000 +0000
@@ -44,12 +44,13 @@
 	return 0;
 }
 
-void plugin_done(void)
+gboolean plugin_done(void)
 {
 	maildir_gtk_done();
 	if (!claws_is_exiting())
 		folder_unregister_class(maildir_get_class());
 	uiddb_done();
+	return TRUE;
 }
 
 const gchar *plugin_name(void)
