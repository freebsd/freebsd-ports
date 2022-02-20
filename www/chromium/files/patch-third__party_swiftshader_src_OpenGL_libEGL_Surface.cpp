--- third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp.orig	2022-02-07 13:39:41 UTC
+++ third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp
@@ -349,7 +349,7 @@ bool WindowSurface::checkForResize()
 
 		int windowWidth = windowAttributes.width;
 		int windowHeight = windowAttributes.height;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 		// Non X11 linux is headless only
 		int windowWidth = 100;
 		int windowHeight = 100;
