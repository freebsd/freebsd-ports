--- ui/gl/gl_image_glx_native_pixmap.cc.orig	2022-02-07 13:39:41 UTC
+++ ui/gl/gl_image_glx_native_pixmap.cc
@@ -14,6 +14,8 @@
 #include "ui/gl/buffer_format_utils.h"
 #include "ui/gl/gl_bindings.h"
 
+#include <unistd.h>
+
 namespace gl {
 
 namespace {
