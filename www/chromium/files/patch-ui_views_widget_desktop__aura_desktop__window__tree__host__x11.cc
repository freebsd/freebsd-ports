--- ui/views/widget/desktop_aura/desktop_window_tree_host_x11.cc.orig	2019-05-28 10:19:21.517467000 +0200
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_x11.cc	2019-05-28 10:22:46.373548000 +0200
@@ -1440,24 +1440,15 @@
   if (swa.override_redirect)
     attribute_mask |= CWOverrideRedirect;
 
-  bool enable_transparent_visuals;
-  switch (params.opacity) {
-    case Widget::InitParams::OPAQUE_WINDOW:
-      enable_transparent_visuals = false;
-      break;
-    case Widget::InitParams::TRANSLUCENT_WINDOW:
-      enable_transparent_visuals = true;
-      break;
-    case Widget::InitParams::INFER_OPACITY:
-    default:
-      enable_transparent_visuals = params.type == Widget::InitParams::TYPE_DRAG;
-  }
-
   Visual* visual = CopyFromParent;
   int depth = CopyFromParent;
   Colormap colormap = CopyFromParent;
+
+  // GLSurfaceGLX always create child window with alpha channel. If the parent
+  // window doesn't have alpha channel, it causes flash, so always request argb
+  // visual.
   ui::XVisualManager::GetInstance()->ChooseVisualForWindow(
-      enable_transparent_visuals, &visual, &depth, &colormap,
+      true /* want_argb_visual */, &visual, &depth, &colormap,
       &use_argb_visual_);
 
   if (colormap != CopyFromParent) {
