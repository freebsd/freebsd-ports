Regressed by https://github.com/KhronosGroup/EGL-Registry/commit/64aa561f1971

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
@@ -36,6 +36,7 @@
 #endif
 
 #if USE(EGL)
+#define USE_X11
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
 #endif
