--- ./content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2014-08-20 21:02:48.000000000 +0200
+++ ./content/browser/renderer_host/render_widget_host_view_aura.cc	2014-08-22 15:06:25.000000000 +0200
@@ -631,7 +631,7 @@
   if (host)
     return reinterpret_cast<gfx::NativeViewId>(host->GetAcceleratedWidget());
 #endif
-  return static_cast<gfx::NativeViewId>(NULL);
+  return static_cast<gfx::NativeViewId>(0);
 }
 
 gfx::NativeViewAccessible RenderWidgetHostViewAura::GetNativeViewAccessible() {
