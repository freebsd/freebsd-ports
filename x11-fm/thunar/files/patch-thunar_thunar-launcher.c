Right click context menu with wrong icon (bug #10652)

--- thunar/thunar-launcher.c.orig	2013-12-18 23:41:57 UTC
+++ thunar/thunar-launcher.c
@@ -815,8 +815,9 @@ thunar_launcher_update_idle (gpointer da
        ** - "Open", "Open in n New Windows" and "Open in n New Tabs" actions
        **/
 
-      /* Prepare "Open" label */
+      /* Prepare "Open" label and icon */
       gtk_action_set_label (launcher->action_open, _("_Open"));
+      gtk_action_set_stock_id (launcher->action_open, GTK_STOCK_OPEN);
 
       if (n_selected_files == n_directories && n_directories >= 1)
         {
@@ -928,6 +929,7 @@ thunar_launcher_update_idle (gpointer da
           /* turn the "Open" action into "Execute" */
           g_object_set (G_OBJECT (launcher->action_open),
                         "label", _("_Execute"),
+                        "stock-id", GTK_STOCK_EXECUTE,
                         "tooltip", ngettext ("Execute the selected file", "Execute the selected files", n_selected_files),
                         NULL);
         }
@@ -945,6 +947,10 @@ thunar_launcher_update_idle (gpointer da
           g_free (tooltip);
           g_free (label);
 
+          /* load default application icon */
+          gtk_action_set_stock_id (launcher->action_open, NULL);
+          gtk_action_set_gicon (launcher->action_open, g_app_info_get_icon (applications->data));
+
           /* remember the default application for the "Open" action */
           g_object_set_qdata_full (G_OBJECT (launcher->action_open), thunar_launcher_handler_quark, applications->data, g_object_unref);
 
