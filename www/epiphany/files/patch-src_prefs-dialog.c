--- src/prefs-dialog.c.orig	Thu Apr 24 02:14:52 2003
+++ src/prefs-dialog.c	Thu Apr 24 02:16:05 2003
@@ -243,13 +243,13 @@
 {
 	GError *err;
 	gint id;
-	err = NULL;
 	gchar *help_preferences[] = {
 		"ephy-preferences-appearance",
 		"ephy-preferences-general",
 		"ephy-preferences-ui",
 		"ephy-preferences-advanced"
 	};
+	err = NULL;
 
 	id = gtk_notebook_get_current_page (GTK_NOTEBOOK (pd->priv->notebook));
 
