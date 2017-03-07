--- src/lxterminal.c.orig	2016-12-20 02:05:51 UTC
+++ src/lxterminal.c
@@ -573,8 +573,8 @@ static void terminal_name_tab_activate_e
         _("Name Tab"),
         GTK_WINDOW(terminal->window),
         0,
-        NULL, GTK_RESPONSE_CANCEL,
-        NULL, GTK_RESPONSE_OK,
+        _("_Cancel"), GTK_RESPONSE_CANCEL,
+        _("_OK"), GTK_RESPONSE_OK,
         NULL);
     gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_OK);
     if (gtk_icon_theme_has_icon(gtk_icon_theme_get_default(), "lxterminal"))
