--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2014-10-02 17:39:47 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -653,7 +653,7 @@
   if (host)
     return reinterpret_cast<gfx::NativeViewId>(host->GetAcceleratedWidget());
 #endif
-  return static_cast<gfx::NativeViewId>(NULL);
+  return static_cast<gfx::NativeViewId>(0);
 }
 
 gfx::NativeViewAccessible RenderWidgetHostViewAura::GetNativeViewAccessible() {
