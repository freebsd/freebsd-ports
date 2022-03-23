No GUdev on OpenBSD (XXX add HAVE_GUDEV to meson_options.txt)
No colord (needs GUdev) on OpenBSD (XXX add HAVE_COLORD to meson_options.txt)

http://permalink.gmane.org/gmane.comp.gnome.desktop/51950
https://bugzilla.gnome.org/show_bug.cgi?id=770758#c3
https://bugzilla.gnome.org/show_bug.cgi?id=766329
https://bugzilla.gnome.org/show_bug.cgi?id=772736 (systemd --user)

Index: shell/cc-panel-loader.c
--- shell/cc-panel-loader.c.orig
+++ shell/cc-panel-loader.c
@@ -36,13 +36,14 @@ extern GType cc_background_panel_get_type (void);
 #ifdef BUILD_BLUETOOTH
 extern GType cc_bluetooth_panel_get_type (void);
 #endif /* BUILD_BLUETOOTH */
-extern GType cc_color_panel_get_type (void);
 extern GType cc_date_time_panel_get_type (void);
 extern GType cc_default_apps_panel_get_type (void);
 extern GType cc_display_panel_get_type (void);
 extern GType cc_info_overview_panel_get_type (void);
 extern GType cc_keyboard_panel_get_type (void);
+#ifdef NOTYET
 extern GType cc_mouse_panel_get_type (void);
+#endif
 extern GType cc_multitasking_panel_get_type (void);
 #ifdef BUILD_NETWORK
 extern GType cc_network_panel_get_type (void);
@@ -55,7 +56,9 @@ extern GType cc_printers_panel_get_type (void);
 extern GType cc_region_panel_get_type (void);
 extern GType cc_removable_media_panel_get_type (void);
 extern GType cc_search_panel_get_type (void);
+#ifdef BUILD_SHARING
 extern GType cc_sharing_panel_get_type (void);
+#endif
 extern GType cc_sound_panel_get_type (void);
 #ifdef BUILD_THUNDERBOLT
 extern GType cc_bolt_panel_get_type (void);
@@ -103,7 +106,6 @@ static CcPanelLoaderVtable default_panels[] =
   PANEL_TYPE("bluetooth",        cc_bluetooth_panel_get_type,            NULL),
 #endif
   PANEL_TYPE("camera",           cc_camera_panel_get_type,               NULL),
-  PANEL_TYPE("color",            cc_color_panel_get_type,                NULL),
   PANEL_TYPE("datetime",         cc_date_time_panel_get_type,            NULL),
   PANEL_TYPE("default-apps",     cc_default_apps_panel_get_type,         NULL),
   PANEL_TYPE("diagnostics",      cc_diagnostics_panel_get_type,          cc_diagnostics_panel_static_init_func),
@@ -113,7 +115,9 @@ static CcPanelLoaderVtable default_panels[] =
   PANEL_TYPE("location",         cc_location_panel_get_type,             NULL),
   PANEL_TYPE("lock",             cc_lock_panel_get_type,                 NULL),
   PANEL_TYPE("microphone",       cc_microphone_panel_get_type,           NULL),
+#ifdef NOTYET
   PANEL_TYPE("mouse",            cc_mouse_panel_get_type,                NULL),
+#endif
   PANEL_TYPE("multitasking",     cc_multitasking_panel_get_type,         NULL),
 #ifdef BUILD_NETWORK
   PANEL_TYPE("network",          cc_network_panel_get_type,              NULL),
@@ -126,7 +130,9 @@ static CcPanelLoaderVtable default_panels[] =
   PANEL_TYPE("region",           cc_region_panel_get_type,               NULL),
   PANEL_TYPE("removable-media",  cc_removable_media_panel_get_type,      NULL),
   PANEL_TYPE("search",           cc_search_panel_get_type,               NULL),
+#ifdef BUILD_SHARING
   PANEL_TYPE("sharing",          cc_sharing_panel_get_type,              NULL),
+#endif
   PANEL_TYPE("sound",            cc_sound_panel_get_type,                NULL),
 #ifdef BUILD_THUNDERBOLT
   PANEL_TYPE("thunderbolt",      cc_bolt_panel_get_type,                 NULL),
