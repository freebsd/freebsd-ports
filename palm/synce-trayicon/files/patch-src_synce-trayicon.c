--- src/synce-trayicon.c	2008/07/12 13:00:38	3510
+++ src/synce-trayicon.c	2008/08/12 20:40:23	3551
@@ -229,7 +229,21 @@
 static void
 password_required_on_device_cb(DccmClient *comms_client, gchar *pdaname, gpointer user_data)
 {
+#ifdef ENABLE_NOTIFY
+
+  SynceTrayIcon *self = SYNCE_TRAYICON(user_data);
+  gchar *notify_string = NULL;
+
+  notify_string = g_strdup_printf("The device %s is locked. Please unlock it by following instructions on the device", pdaname);
+  event_notification(self, "Device locked", notify_string);
+  g_free(notify_string);
+
+#else  /* ENABLE_NOTIFY */
+
   device_do_password_on_device_dialog(pdaname);
+
+#endif /* ENABLE_NOTIFY */
+
 }
 
 static void
@@ -471,17 +485,6 @@
 }
 
 static void
-menu_software (GtkWidget *button, SynceTrayIcon *self)
-{
-  char *argv[1] = {
-    SYNCE_SOFTWARE_MANAGER
-  };
-  if (gnome_execute_async(NULL,1, argv) == -1) {
-    synce_error_dialog(_("Can't open the software manager\nmake sure you have synce-software-manager installed"));
-  }
-}
-
-static void
 menu_preferences (GtkWidget *button, SynceTrayIcon *self)
 {
   run_prefs_dialog(self);
