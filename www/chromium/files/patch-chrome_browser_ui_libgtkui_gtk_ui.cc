--- chrome/browser/ui/libgtkui/gtk_ui.cc.orig	2017-07-21 03:22:08.117746000 +0200
+++ chrome/browser/ui/libgtkui/gtk_ui.cc	2017-07-21 03:25:59.536126000 +0200
@@ -315,52 +315,15 @@
   return params;
 }
 
-float GtkDpiToScaleFactor(int dpi) {
-  // GTK multiplies the DPI by 1024 before storing it.
-  return dpi / (1024 * kDefaultDPI);
-}
-
-gint GetGdkScreenSettingInt(const char* setting_name) {
-  GValue value = G_VALUE_INIT;
-  g_value_init(&value, G_TYPE_INT);
-  if (!gdk_screen_get_setting(gdk_screen_get_default(), setting_name, &value))
-    return -1;
-  return g_value_get_int(&value);
-}
-
-float GetScaleFromGdkScreenSettings() {
-  gint window_scale = GetGdkScreenSettingInt("gdk-window-scaling-factor");
-  if (window_scale <= 0)
-    return -1;
-  gint font_dpi = GetGdkScreenSettingInt("gdk-unscaled-dpi");
-  if (font_dpi <= 0)
-    return -1;
-  return window_scale * GtkDpiToScaleFactor(font_dpi);
-}
-
-float GetScaleFromXftDPI() {
-  GtkSettings* gtk_settings = gtk_settings_get_default();
-  CHECK(gtk_settings);
-  gint gtk_dpi = -1;
-  g_object_get(gtk_settings, "gtk-xft-dpi", &gtk_dpi, nullptr);
-  if (gtk_dpi <= 0)
-    return -1;
-  return GtkDpiToScaleFactor(gtk_dpi);
-}
-
 float GetRawDeviceScaleFactor() {
   if (display::Display::HasForceDeviceScaleFactor())
     return display::Display::GetForcedDeviceScaleFactor();
 
-  float scale = GetScaleFromGdkScreenSettings();
-  if (scale > 0)
-    return scale;
-
-  scale = GetScaleFromXftDPI();
-  if (scale > 0)
-    return scale;
-
-  return 1;
+  GdkScreen* screen = gdk_screen_get_default();
+  gint scale = gdk_screen_get_monitor_scale_factor(
+      screen, gdk_screen_get_primary_monitor(screen));
+  gdouble resolution = gdk_screen_get_resolution(screen);
+  return resolution <= 0? scale : resolution * scale / kDefaultDPI;
 }
 
 views::LinuxUI::NonClientMiddleClickAction GetDefaultMiddleClickAction() {
