--- xbmc/windowing/X11/GLContextEGL.h.orig	2022-03-02 18:38:51 UTC
+++ xbmc/windowing/X11/GLContextEGL.h
@@ -13,7 +13,7 @@
 #include "threads/CriticalSection.h"
 
 #include <EGL/eglext.h>
-#include <EGL/eglextchromium.h>
+#include <EGL/eglext_angle.h>
 #include <X11/Xutil.h>
 
 class CGLContextEGL : public CGLContext
