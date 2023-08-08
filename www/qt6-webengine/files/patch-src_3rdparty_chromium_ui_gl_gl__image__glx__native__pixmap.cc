--- src/3rdparty/chromium/ui/gl/gl_image_glx_native_pixmap.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/gl/gl_image_glx_native_pixmap.cc
@@ -12,6 +12,8 @@
 #include "ui/gl/buffer_format_utils.h"
 #include "ui/gl/glx_util.h"
 
+#include <unistd.h>
+
 namespace gl {
 
 GLImageGLXNativePixmap::GLImageGLXNativePixmap(const gfx::Size& size,
