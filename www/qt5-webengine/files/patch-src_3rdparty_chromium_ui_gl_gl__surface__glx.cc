--- src/3rdparty/chromium/ui/gl/gl_surface_glx.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/ui/gl/gl_surface_glx.cc
@@ -461,7 +461,10 @@ bool GLSurfaceGLX::InitializeOneOff() {
     return false;
   }
 
-  const auto& visual_info = gl::GLVisualPickerGLX::GetInstance()->rgba_visual();
+  const auto& visual_info = 
+    ui::IsCompositingManagerPresent()
+      ? gl::GLVisualPickerGLX::GetInstance()->rgba_visual()
+      : gl::GLVisualPickerGLX::GetInstance()->system_visual();
   g_visual = visual_info.visual;
   g_depth = visual_info.depth;
   g_colormap =
