--- gpu/command_buffer/tests/gl_test_utils.cc.orig	2021-04-14 18:41:04 UTC
+++ gpu/command_buffer/tests/gl_test_utils.cc
@@ -24,7 +24,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/init/gl_factory.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/gl/gl_image_native_pixmap.h"
 #endif
 
@@ -451,7 +451,7 @@ void GpuCommandBufferTestEGL::RestoreGLDefault() {
   window_system_binding_info_ = gl::GLWindowSystemBindingInfo();
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 scoped_refptr<gl::GLImageNativePixmap>
 GpuCommandBufferTestEGL::CreateGLImageNativePixmap(gfx::BufferFormat format,
                                                    gfx::Size size,
