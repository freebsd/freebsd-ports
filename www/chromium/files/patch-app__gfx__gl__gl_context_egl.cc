--- app/gfx/gl/gl_context_egl.cc.orig	2011-01-26 10:30:13.000000000 +0100
+++ app/gfx/gl/gl_context_egl.cc	2011-01-30 13:55:55.000000000 +0100
@@ -4,7 +4,7 @@
 
 #include <EGL/egl.h>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 extern "C" {
 #include <X11/Xlib.h>
 }
@@ -82,7 +82,7 @@
   if (initialized)
     return true;
 
-#ifdef OS_LINUX
+#ifdef OS_LINUX || defined(OS_FREEBSD)
   EGLNativeDisplayType native_display = XOpenDisplay(NULL);
 #else
   EGLNativeDisplayType native_display = EGL_DEFAULT_DISPLAY;
