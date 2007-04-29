--- src/users/user-settings.c.orig	Sun Apr 22 23:32:58 2007
+++ src/users/user-settings.c	Sun Apr 22 23:34:18 2007
@@ -632,10 +632,10 @@
 		password_changed = GPOINTER_TO_INT (g_object_get_data (G_OBJECT (widget), "changed"));
 
 		if (password_changed)
-			oobs_user_set_password (user, gtk_entry_get_text (GTK_ENTRY (widget)));
+			oobs_user_set_crypted_password (user, gtk_entry_get_text (GTK_ENTRY (widget)));
 	} else {
 		widget = gst_dialog_get_widget (tool->main_dialog, "user_settings_random_passwd");
-		oobs_user_set_password (user, gtk_entry_get_text (GTK_ENTRY (widget)));
+		oobs_user_set_crypted_password (user, gtk_entry_get_text (GTK_ENTRY (widget)));
 	}
 
 	group = get_main_group (oobs_user_get_login_name (user));
