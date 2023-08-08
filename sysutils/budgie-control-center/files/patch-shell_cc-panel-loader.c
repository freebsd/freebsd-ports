--- shell/cc-panel-loader.c.orig	2022-09-13 15:10:03 UTC
+++ shell/cc-panel-loader.c
@@ -37,7 +37,9 @@ extern GType cc_background_panel_get_type (void);
 extern GType cc_bluetooth_panel_get_type (void);
 #endif /* BUILD_BLUETOOTH */
 extern GType cc_color_panel_get_type (void);
+#ifdef BUILD_DATETIME
 extern GType cc_date_time_panel_get_type (void);
+#endif /* BUILD_DATETIME */
 extern GType cc_default_apps_panel_get_type (void);
 extern GType cc_display_panel_get_type (void);
 extern GType cc_info_overview_panel_get_type (void);
@@ -102,7 +104,9 @@ static CcPanelLoaderVtable default_panels[] =
 #endif
   //PANEL_TYPE("camera",           cc_camera_panel_get_type,               NULL),
   PANEL_TYPE("color",            cc_color_panel_get_type,                NULL),
+#ifdef BUILD_DATETIME
   PANEL_TYPE("datetime",         cc_date_time_panel_get_type,            NULL),
+#endif
   PANEL_TYPE("default-apps",     cc_default_apps_panel_get_type,         NULL),
   PANEL_TYPE("diagnostics",      cc_diagnostics_panel_get_type,          cc_diagnostics_panel_static_init_func),
   PANEL_TYPE("display",          cc_display_panel_get_type,              NULL),
