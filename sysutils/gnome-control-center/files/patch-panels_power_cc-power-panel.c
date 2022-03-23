--- panels/power/cc-power-panel.c.orig	2021-10-22 02:27:08 UTC
+++ panels/power/cc-power-panel.c
@@ -1641,9 +1641,6 @@ cc_power_panel_init (CcPowerPanel *self)
   setup_power_profiles (self);
 
   setup_power_saving (self);
-  g_settings_bind (self->gsd_settings, "power-saver-profile-on-low-battery",
-                   self->power_saver_low_battery_switch, "active",
-                   G_SETTINGS_BIND_DEFAULT);
 
   setup_general_section (self);
 
