--- Source/WebCore/platform/graphics/egl/GLContextEGL.cpp.orig	2015-07-10 13:10:10.413595000 +0200
+++ Source/WebCore/platform/graphics/egl/GLContextEGL.cpp	2015-07-10 13:10:48.159246000 +0200
@@ -42,6 +42,8 @@
 #endif
 #endif
 
+#include <X11/Xlib.h>
+
 #if ENABLE(ACCELERATED_2D_CANVAS)
 // cairo-gl.h includes some definitions from GLX that conflict with
 // the ones provided by us. Since GLContextEGL doesn't use any GLX
