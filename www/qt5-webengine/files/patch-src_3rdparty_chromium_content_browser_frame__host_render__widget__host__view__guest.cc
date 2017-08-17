--- src/3rdparty/chromium/content/browser/frame_host/render_widget_host_view_guest.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/content/browser/frame_host/render_widget_host_view_guest.cc
@@ -338,11 +338,11 @@ gfx::NativeView RenderWidgetHostViewGuest::GetNativeVi
 
 gfx::NativeViewId RenderWidgetHostViewGuest::GetNativeViewId() const {
   if (!guest_)
-    return static_cast<gfx::NativeViewId>(NULL);
+    return reinterpret_cast<gfx::NativeViewId>(NULL);
 
   RenderWidgetHostView* rwhv = guest_->GetOwnerRenderWidgetHostView();
   if (!rwhv)
-    return static_cast<gfx::NativeViewId>(NULL);
+    return reinterpret_cast<gfx::NativeViewId>(NULL);
   return rwhv->GetNativeViewId();
 }
 
