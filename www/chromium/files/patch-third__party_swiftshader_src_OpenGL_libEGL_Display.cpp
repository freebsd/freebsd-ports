--- third_party/swiftshader/src/OpenGL/libEGL/Display.cpp.orig	2017-06-26 22:14:07.363371000 +0200
+++ third_party/swiftshader/src/OpenGL/libEGL/Display.cpp	2017-06-26 22:15:57.992270000 +0200
@@ -30,7 +30,7 @@
 #include <sys/ioctl.h>
 #include <linux/fb.h>
 #include <fcntl.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "Main/libX11.hpp"
 #elif defined(__APPLE__)
 #include "OSXUtils.hpp"
@@ -53,7 +53,7 @@
 
 	static void *nativeDisplay = nullptr;
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		// Even if the application provides a native display handle, we open (and close) our own connection
 		if(!nativeDisplay && dpy != HEADLESS_DISPLAY && libX11 && libX11->XOpenDisplay)
 		{
@@ -76,7 +76,7 @@
 {
 	terminate();
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		if(nativeDisplay && libX11->XCloseDisplay)
 		{
 			libX11->XCloseDisplay((::Display*)nativeDisplay);
@@ -550,7 +550,7 @@
 			return false;
 		}
 		return true;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__)
 		if(nativeDisplay)
 		{
 			XWindowAttributes windowAttributes;
@@ -707,7 +707,7 @@
 
 		// No framebuffer device found, or we're in user space
 		return sw::FORMAT_X8B8G8R8;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__)
 		if(nativeDisplay)
 		{
 			Screen *screen = libX11->XDefaultScreenOfDisplay((::Display*)nativeDisplay);
