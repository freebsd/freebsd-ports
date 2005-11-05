--- src/gnome-keyring-manager-acl-display.c.orig	Sat Jul  2 02:12:49 2005
+++ src/gnome-keyring-manager-acl-display.c	Sat Jul  2 02:16:31 2005
@@ -393,13 +393,15 @@ gkm_acl_display_set_acl (GKMAclDisplay *
       GnomeKeyringAccessType at;
       GtkTreeIter iter;
       char *name, *path;
+      const char *app_path;
 
       ac = (GnomeKeyringAccessControl*) tmp->data;
       name = gnome_keyring_item_ac_get_display_name (ac);
       path = gnome_keyring_item_ac_get_path_name (ac);
+      app_path = gkm_get_application_path ();
 
       /* We don't want to include ourself in the list. */
-      if (g_str_equal (path, gkm_get_application_path ()))
+      if (app_path && g_str_equal (path, app_path))
 	{
 	  self->priv->gkm_ac = gnome_keyring_access_control_copy (ac);
 	}
