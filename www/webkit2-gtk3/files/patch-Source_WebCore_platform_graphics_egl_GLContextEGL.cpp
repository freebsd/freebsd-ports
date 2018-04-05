--- Source/WebCore/platform/graphics/egl/GLContextEGL.cpp.orig	2018-02-19 07:45:32 UTC
+++ Source/WebCore/platform/graphics/egl/GLContextEGL.cpp
@@ -44,6 +44,8 @@
 #include "OpenGLShims.h"
 #endif
 
+#include <X11/Xlib.h>
+
 #if ENABLE(ACCELERATED_2D_CANVAS)
 // cairo-gl.h includes some definitions from GLX that conflict with
 // the ones provided by us. Since GLContextEGL doesn't use any GLX
