--- src/gnome-keyring-manager-keyring-manager.c.orig	Mon Jul 12 23:14:24 2004
+++ src/gnome-keyring-manager-keyring-manager.c	Mon Jul 12 23:15:32 2004
@@ -240,6 +240,13 @@
   GtkWidget *menubar;
   GtkWidget *menu_item;
   GError *error;
+  SetColumnPrefsData toggle[] = 
+  {
+    { COLUMN_LOCK_ON_IDLE, "ToggleLockOnIdle",       "lock-on-idle" },
+    { COLUMN_LOCK_TIMEOUT, "ToggleLockTimeout",      "lock-timeout" },
+    { COLUMN_MTIME,        "ToggleModificationTime", "mtime" },
+    { COLUMN_CTIME,        "ToggleCreationTime",     "ctime" }
+  };
 
   manager->priv = g_new0 (GKMKeyringManagerPrivate, 1);
 
@@ -329,13 +336,6 @@
   g_signal_connect (manager->priv->tree_view, "button-press-event", G_CALLBACK (keyring_tree_button_press_callback), manager);
   g_signal_connect (manager->priv->tree_view, "popup-menu", G_CALLBACK (keyring_tree_context_menu_callback), manager);
   
-  SetColumnPrefsData toggle[] = 
-  {
-    { COLUMN_LOCK_ON_IDLE, "ToggleLockOnIdle",       "lock-on-idle" },
-    { COLUMN_LOCK_TIMEOUT, "ToggleLockTimeout",      "lock-timeout" },
-    { COLUMN_MTIME,        "ToggleModificationTime", "mtime" },
-    { COLUMN_CTIME,        "ToggleCreationTime",     "ctime" }
-  };
   manager->priv->gconf_cnxn_ids = 
   set_column_visibility_preferences (toggle,
   				     G_N_ELEMENTS (toggle),
