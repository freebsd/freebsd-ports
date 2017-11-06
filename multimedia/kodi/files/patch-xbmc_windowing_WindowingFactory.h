--- xbmc/windowing/WindowingFactory.h.orig	2015-11-12 02:33:50 UTC
+++ xbmc/windowing/WindowingFactory.h
@@ -38,11 +38,14 @@
 #elif defined(TARGET_LINUX)   && defined(HAS_GLES) && defined(HAS_EGL) && !defined(HAVE_X11)
 #include "egl/WinSystemEGL.h"
 
-#elif defined(TARGET_FREEBSD)   && defined(HAS_GL)   && defined(HAVE_X11)
-#include "X11/WinSystemX11GL.h"
+#elif defined(TARGET_FREEBSD)   && defined(HAVE_X11)   && defined(HAS_GL)
+#include "X11/WinSystemX11GLContext.h"
 
-#elif defined(TARGET_FREEBSD) && defined(HAS_GLES) && defined(HAS_EGL)
-#include "egl/WinSystemGLES.h"
+#elif defined(TARGET_FREEBSD)   && defined(HAVE_X11)   && defined(HAS_GLES)
+#include "X11/WinSystemX11GLESContext.h"
+
+#elif defined(TARGET_FREEBSD)  && defined(TARGET_RASPBERRY_PI)
+#include "egl/WinSystemEGL.h"
 
 #elif defined(TARGET_DARWIN_OSX)
 #include "osx/WinSystemOSXGL.h"
