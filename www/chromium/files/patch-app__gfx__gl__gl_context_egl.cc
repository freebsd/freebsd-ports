--- app/gfx/gl/gl_context_egl.cc.orig	2011-04-16 11:01:07.000000000 +0300
+++ app/gfx/gl/gl_context_egl.cc	2011-04-25 21:52:13.940147280 +0300
@@ -13,7 +13,7 @@
 // it brings in #defines that cause conflicts.
 #include "app/gfx/gl/gl_bindings.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 extern "C" {
 #include <X11/Xlib.h>
 }
@@ -85,7 +85,7 @@
   if (initialized)
     return true;
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   EGLNativeDisplayType native_display = XOpenDisplay(NULL);
 #else
   EGLNativeDisplayType native_display = EGL_DEFAULT_DISPLAY;
