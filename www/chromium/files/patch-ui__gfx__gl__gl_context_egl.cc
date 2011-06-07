--- ui/gfx/gl/gl_context_egl.cc.orig	2011-05-06 12:03:42.000000000 +0300
+++ ui/gfx/gl/gl_context_egl.cc	2011-06-05 16:26:28.775163463 +0300
@@ -15,7 +15,7 @@
 // it brings in #defines that cause conflicts.
 #include "ui/gfx/gl/gl_bindings.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 extern "C" {
 #include <X11/Xlib.h>
 }
