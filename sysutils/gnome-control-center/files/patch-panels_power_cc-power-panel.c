--- panels/power/cc-power-panel.c.orig	2025-02-04 21:56:28 UTC
+++ panels/power/cc-power-panel.c
@@ -719,9 +719,9 @@ can_suspend_or_hibernate (CcPowerPanel *self,
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
@@ -1432,9 +1432,9 @@ cc_power_panel_init (CcPowerPanel *self)
   setup_power_profiles (self);
 
   setup_power_saving (self);
-  g_settings_bind (self->gsd_settings, "power-saver-profile-on-low-battery",
+  /*g_settings_bind (self->gsd_settings, "power-saver-profile-on-low-battery",
                    self->power_saver_low_battery_row, "active",
-                   G_SETTINGS_BIND_DEFAULT);
+                   G_SETTINGS_BIND_DEFAULT);*/
 
   setup_general_section (self);
 
