--- third_party/swiftshader/src/OpenGL/libEGL/EGLSurface.cpp.orig	2017-06-26 22:17:25.800342000 +0200
+++ third_party/swiftshader/src/OpenGL/libEGL/EGLSurface.cpp	2017-06-26 22:18:03.230149000 +0200
@@ -26,7 +26,7 @@
 #include "common/debug.h"
 #include "Main/FrameBuffer.hpp"
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 #include "Main/libX11.hpp"
 #elif defined(_WIN32)
 #include <tchar.h>
@@ -278,7 +278,7 @@
 	#elif defined(__ANDROID__)
 		int windowWidth;  window->query(window, NATIVE_WINDOW_WIDTH, &windowWidth);
 		int windowHeight; window->query(window, NATIVE_WINDOW_HEIGHT, &windowHeight);
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__)
 		XWindowAttributes windowAttributes;
 		libX11->XGetWindowAttributes((::Display*)display->getNativeDisplay(), window, &windowAttributes);
 
