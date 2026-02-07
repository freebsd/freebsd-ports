--- shell/cc-panel-loader.c.orig	2025-04-14 07:07:35 UTC
+++ shell/cc-panel-loader.c
@@ -52,7 +52,9 @@ extern GType cc_search_panel_get_type (void);
 extern GType cc_printers_panel_get_type (void);
 extern GType cc_privacy_panel_get_type (void);
 extern GType cc_search_panel_get_type (void);
+#ifdef BUILD_SHARING
 extern GType cc_sharing_panel_get_type (void);
+#endif /* BUILD_SHARING */
 extern GType cc_sound_panel_get_type (void);
 extern GType cc_system_panel_get_type (void);
 extern GType cc_ua_panel_get_type (void);
@@ -67,7 +69,9 @@ extern void cc_wifi_panel_static_init_func (void);
 #ifdef BUILD_NETWORK
 extern void cc_wifi_panel_static_init_func (void);
 #endif /* BUILD_NETWORK */
+#ifdef BUILD_SHARING
 extern void cc_sharing_panel_static_init_func (void);
+#endif /* BUILD_SHARING */
 #ifdef BUILD_WACOM
 extern void cc_wacom_panel_static_init_func (void);
 #endif /* BUILD_WACOM */
@@ -105,7 +109,9 @@ static CcPanelLoaderVtable default_panels[] =
   PANEL_TYPE("printers",         cc_printers_panel_get_type,             NULL),
   PANEL_TYPE("privacy",          cc_privacy_panel_get_type,              NULL),
   PANEL_TYPE("search",           cc_search_panel_get_type,               NULL),
+#ifdef BUILD_SHARING
   PANEL_TYPE("sharing",          cc_sharing_panel_get_type,              cc_sharing_panel_static_init_func),
+#endif
   PANEL_TYPE("sound",            cc_sound_panel_get_type,                NULL),
   PANEL_TYPE("system",           cc_system_panel_get_type,               NULL),
   PANEL_TYPE("universal-access", cc_ua_panel_get_type,                   NULL),
