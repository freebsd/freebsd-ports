--- ui/gl/gl_surface_glx.cc.orig	2019-12-16 21:51:34 UTC
+++ ui/gl/gl_surface_glx.cc
@@ -459,7 +459,10 @@ bool GLSurfaceGLX::InitializeOneOff() {
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
