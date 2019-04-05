--- gpu/command_buffer/tests/gl_test_utils.h.orig	2019-03-17 17:06:38 UTC
+++ gpu/command_buffer/tests/gl_test_utils.h
@@ -112,7 +112,7 @@ class GpuCommandBufferTestEGL {
     return gfx::HasExtension(gl_extensions_, extension);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Create GLImageNativePixmap filled in with the given pixels.
   scoped_refptr<gl::GLImageNativePixmap> CreateGLImageNativePixmap(
       gfx::BufferFormat format,
