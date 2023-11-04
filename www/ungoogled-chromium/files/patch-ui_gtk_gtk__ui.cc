--- ui/gtk/gtk_ui.cc.orig	2023-11-04 07:08:51 UTC
+++ ui/gtk/gtk_ui.cc
@@ -993,11 +993,19 @@ ui::DisplayConfig GtkUi::GetDisplayConfig() const {
     GdkRectangle geometry;
     gdk_monitor_get_geometry(monitor, &geometry);
     int monitor_scale = std::max(1, gdk_monitor_get_scale_factor(monitor));
+#if defined(__clang__) && (__clang_major__ >= 16)
     config.display_geometries.emplace_back(
         gfx::Rect(monitor_scale * geometry.x, monitor_scale * geometry.y,
                   monitor_scale * geometry.width,
                   monitor_scale * geometry.height),
         monitor_scale * font_scale);
+#else
+    config.display_geometries.emplace_back() = {
+        gfx::Rect(monitor_scale * geometry.x, monitor_scale * geometry.y,
+                  monitor_scale * geometry.width,
+                  monitor_scale * geometry.height),
+        static_cast<float>(monitor_scale * font_scale)};
+#endif
   }
   return config;
 }
