--- plugins/power/csd-power-manager.c.orig	2013-11-25 18:39:23.000000000 +0000
+++ plugins/power/csd-power-manager.c	2014-04-04 09:06:44.968035344 +0000
@@ -1158,7 +1158,11 @@
         GError *error = NULL;
 
         /* get devices from UPower */
+#ifdef HAVE_OLD_UPOWER
         ret = up_client_enumerate_devices_sync (manager->priv->up_client, NULL, &error);
+#else
+        ret = FALSE;
+#endif
         if (!ret) {
                 g_warning ("failed to get device list: %s", error->message);
                 g_error_free (error);
@@ -1306,13 +1310,17 @@
 
         policy = g_settings_get_enum (manager->priv->settings, "critical-battery-action");
         if (policy == CSD_POWER_ACTION_SUSPEND) {
+#ifdef HAVE_OLD_UPOWER
                 if (is_ups == FALSE &&
                     up_client_get_can_suspend (manager->priv->up_client))
                         return policy;
+#endif
                 return CSD_POWER_ACTION_SHUTDOWN;
         } else if (policy == CSD_POWER_ACTION_HIBERNATE) {
+#ifdef HAVE_OLD_UPOWER
                 if (up_client_get_can_hibernate (manager->priv->up_client))
                         return policy;
+#endif
                 return CSD_POWER_ACTION_SHUTDOWN;
         }
 
@@ -2303,7 +2311,11 @@
         /* check we won't melt when the lid is closed */
         if (action_type != CSD_POWER_ACTION_SUSPEND &&
             action_type != CSD_POWER_ACTION_HIBERNATE) {
+#ifdef HAVE_OLD_UPOWER
                 if (up_client_get_lid_force_sleep (manager->priv->up_client)) {
+#else
+                if (0){
+#endif
                         g_warning ("to prevent damage, now forcing suspend");
                         do_power_action_type (manager, CSD_POWER_ACTION_SUSPEND);
                         return;
@@ -2377,7 +2389,11 @@
         }
 
         /* same state */
+#ifdef HAVE_OLD_UPOWER
         tmp = up_client_get_lid_is_closed (manager->priv->up_client);
+#else
+        tmp = FALSE;
+#endif
         if (manager->priv->lid_is_closed == tmp)
                 return;
         manager->priv->lid_is_closed = tmp;
@@ -3539,6 +3555,7 @@
                                       manager);
 }
 
+#ifdef HAVE_OLD_UPOWER
 static void
 upower_notify_sleep_cb (UpClient *client,
                         UpSleepKind sleep_kind,
@@ -3602,6 +3619,7 @@
                 g_error_free (error);
         }
 }
+#endif
 
 static void
 idle_send_to_sleep (CsdPowerManager *manager)
@@ -3838,11 +3856,15 @@
                           G_CALLBACK (engine_settings_key_changed_cb), manager);
         manager->priv->settings_screensaver = g_settings_new ("org.cinnamon.desktop.screensaver");
         manager->priv->up_client = up_client_new ();
+#ifdef HAVE_OLD_UPOWER
         g_signal_connect (manager->priv->up_client, "notify-sleep",
                           G_CALLBACK (upower_notify_sleep_cb), manager);
         g_signal_connect (manager->priv->up_client, "notify-resume",
                           G_CALLBACK (upower_notify_resume_cb), manager);
         manager->priv->lid_is_closed = up_client_get_lid_is_closed (manager->priv->up_client);
+#else
+        manager->priv->lid_is_closed = FALSE;
+#endif
         g_signal_connect (manager->priv->up_client, "device-added",
                           G_CALLBACK (engine_device_added_cb), manager);
         g_signal_connect (manager->priv->up_client, "device-removed",
