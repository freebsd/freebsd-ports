--- ./content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2014-08-12 21:01:24.000000000 +0200
+++ ./content/browser/renderer_host/render_widget_host_view_aura.cc	2014-08-13 09:56:57.000000000 +0200
@@ -626,7 +626,7 @@
   if (host)
     return reinterpret_cast<gfx::NativeViewId>(host->GetAcceleratedWidget());
 #endif
-  return static_cast<gfx::NativeViewId>(NULL);
+  return static_cast<gfx::NativeViewId>(0);
 }
 
 gfx::NativeViewAccessible RenderWidgetHostViewAura::GetNativeViewAccessible() {
