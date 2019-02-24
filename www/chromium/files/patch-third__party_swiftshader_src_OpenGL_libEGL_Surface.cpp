--- third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp.orig	2019-01-12 22:56:53.902120000 +0100
+++ third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp	2019-01-12 22:57:13.884671000 +0100
@@ -352,7 +352,7 @@
 
 		int windowWidth = windowAttributes.width;
 		int windowHeight = windowAttributes.height;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__)
 		// Non X11 linux is headless only
 		int windowWidth = 100;
 		int windowHeight = 100;
