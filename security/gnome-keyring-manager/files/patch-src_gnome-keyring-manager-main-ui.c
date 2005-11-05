--- src/gnome-keyring-manager-main-ui.c.orig	Fri Jun 10 19:59:37 2005
+++ src/gnome-keyring-manager-main-ui.c	Fri Jun 10 19:59:45 2005
@@ -1100,6 +1100,7 @@ gkm_main_ui_initialize_menu (GKMMainUI *
 {
   GtkWidget *menubar;
   GtkAccelGroup *accel_group;
+  GError *error = NULL;
 
   self->priv->action_group = gtk_action_group_new ("MenuActions"); 
   gtk_action_group_add_actions (self->priv->action_group, entries, 
@@ -1111,7 +1112,6 @@ gkm_main_ui_initialize_menu (GKMMainUI *
 				      self->priv->action_group, 0);
   accel_group = gtk_ui_manager_get_accel_group (self->priv->ui_manager);
   gtk_window_add_accel_group (GTK_WINDOW (self->priv->window), accel_group);
-  GError *error = NULL;
   if (!gtk_ui_manager_add_ui_from_file (self->priv->ui_manager,
 					GLADEDIR MENU_FILE,
 					&error))
