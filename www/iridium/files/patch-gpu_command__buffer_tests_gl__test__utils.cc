--- gpu/command_buffer/tests/gl_test_utils.cc.orig	2019-03-17 17:06:00 UTC
+++ gpu/command_buffer/tests/gl_test_utils.cc
@@ -22,7 +22,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gl/init/gl_factory.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gl/gl_image_native_pixmap.h"
 #endif
 
@@ -425,7 +425,7 @@ void GpuCommandBufferTestEGL::RestoreGLDefault() {
   window_system_binding_info_ = gl::GLWindowSystemBindingInfo();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 scoped_refptr<gl::GLImageNativePixmap>
 GpuCommandBufferTestEGL::CreateGLImageNativePixmap(gfx::BufferFormat format,
                                                    gfx::Size size,
