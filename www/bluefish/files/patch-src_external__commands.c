--- src/external_commands.c.orig	2023-07-04 14:12:18 UTC
+++ src/external_commands.c
@@ -483,7 +483,7 @@ create_commandstring(Texternalp * ep, const gchar * fo
 		gtk_dialog_set_default_response(GTK_DIALOG(dialog),GTK_RESPONSE_ACCEPT);
 		tmp = g_strdup_printf(_("Supply arguments to define %%a in '%s'"), formatstring);
 		entry = dialog_entry_labeled(NULL, tmp, gtk_dialog_get_content_area(GTK_DIALOG(dialog)), 6);
-		g_signal_connect(G_OBJECT(entry), "activate", command_dialog_entry_activated_lcb, dialog);
+		g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK(command_dialog_entry_activated_lcb), dialog);
 		g_free(tmp);
 		gtk_widget_show_all(dialog);
 		result = gtk_dialog_run(GTK_DIALOG(dialog));
