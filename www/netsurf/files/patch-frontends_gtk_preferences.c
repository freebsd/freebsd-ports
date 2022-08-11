--- frontends/gtk/preferences.c.orig	2021-04-01 17:51:28 UTC
+++ frontends/gtk/preferences.c
@@ -962,11 +962,26 @@ GtkWidget* nsgtk_preferences(struct browser_window *bw
 		return GTK_WIDGET(priv->dialog);
 	}
 
-	res = nsgtk_builder_new_from_resname("options", &preferences_builder);
-	if (res != NSERROR_OK) {
-		NSLOG(netsurf, INFO, "Preferences UI builder init failed");
-		return NULL;
+	const char *client_lang;
+	char ui_lang[10] = "en";
+        client_lang = getenv("LANG");
+	
+	if (strlen(client_lang)>1)
+	{
+		strncpy(ui_lang,client_lang,2);
 	}
+
+	strcat(ui_lang,"options");
+	
+	res = nsgtk_builder_new_from_resname(ui_lang, &preferences_builder);
+        if (res != NSERROR_OK) {
+                //LANG not found, so fall back to english i guess
+                res = nsgtk_builder_new_from_resname("enoptions", &preferences_builder);
+        }
+        if (res != NSERROR_OK) {
+                NSLOG(netsurf, INFO, "Preferences UI builder init failed");
+                return NULL;
+        }
 
 	priv->dialog = gtk_builder_get_object(preferences_builder,
 					       "dialogPreferences");
