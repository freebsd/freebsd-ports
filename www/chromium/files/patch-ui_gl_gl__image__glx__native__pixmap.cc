--- ui/gl/gl_image_glx_native_pixmap.cc.orig	2022-08-31 12:19:35 UTC
+++ ui/gl/gl_image_glx_native_pixmap.cc
@@ -12,6 +12,8 @@
 #include "ui/gl/buffer_format_utils.h"
 #include "ui/gl/glx_util.h"
 
+#include <unistd.h>
+
 namespace gl {
 
 GLImageGLXNativePixmap::GLImageGLXNativePixmap(const gfx::Size& size,
