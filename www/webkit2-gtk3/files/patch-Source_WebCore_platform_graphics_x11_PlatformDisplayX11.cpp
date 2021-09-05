Regressed by https://github.com/KhronosGroup/EGL-Registry/commit/64aa561f1971
Part of https://github.com/WebKit/WebKit/commit/29421afdcd64

Source/WebCore/platform/graphics/x11/PlatformDisplayX11.cpp:132:5: error: unknown type name 'XVisualInfo'
    XVisualInfo visualTemplate;
    ^
Source/WebCore/platform/graphics/x11/PlatformDisplayX11.cpp:136:5: error: unknown type name 'XVisualInfo'
    XVisualInfo* visualInfo = XGetVisualInfo(m_display, VisualScreenMask, &visualTemplate, &visualCount);
    ^
Source/WebCore/platform/graphics/x11/PlatformDisplayX11.cpp:136:57: error: use of undeclared identifier 'VisualScreenMask'
    XVisualInfo* visualInfo = XGetVisualInfo(m_display, VisualScreenMask, &visualTemplate, &visualCount);
                                                        ^

--- Source/WebCore/platform/graphics/x11/PlatformDisplayX11.cpp.orig	2020-08-12 09:17:55 UTC
+++ Source/WebCore/platform/graphics/x11/PlatformDisplayX11.cpp
@@ -32,6 +32,7 @@
 #include <X11/Xlib.h>
 #include <X11/extensions/Xcomposite.h>
 #if PLATFORM(GTK)
+#include <X11/Xutil.h>
 #include <X11/extensions/Xdamage.h>
 #endif
 
