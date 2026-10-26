--- panels/power/cc-power-panel.c.orig	2022-09-13 15:10:03 UTC
+++ panels/power/cc-power-panel.c
@@ -903,9 +903,9 @@ can_suspend_or_hibernate (CcPowerPanel *self,
     }
 
   variant = g_dbus_connection_call_sync (connection,
-                                         "org.freedesktop.login1",
-                                         "/org/freedesktop/login1",
-                                         "org.freedesktop.login1.Manager",
+                                         "org.freedesktop.ConsoleKit",
+                                         "/org/freedesktop/ConsoleKit/Manager",
+                                         "org.freedesktop.ConsoleKit.Manager",
                                          method_name,
                                          NULL,
                                          NULL,
@@ -1619,9 +1619,9 @@ cc_power_panel_init (CcPowerPanel *self)
   setup_power_profiles (self);
 
   setup_power_saving (self);
-  g_settings_bind (self->gsd_settings, "power-saver-profile-on-low-battery",
+  /*g_settings_bind (self->gsd_settings, "power-saver-profile-on-low-battery",
                    self->power_saver_low_battery_switch, "active",
-                   G_SETTINGS_BIND_DEFAULT);
+                   G_SETTINGS_BIND_DEFAULT);*/
 
   setup_general_section (self);
 
