--- third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp.orig	2017-09-05 21:06:52.000000000 +0200
+++ third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp	2017-09-07 00:17:09.604043000 +0200
@@ -25,7 +25,7 @@
 
 #if defined(__ANDROID__)
 #include <system/window.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "Main/libX11.hpp"
 #endif
 
@@ -118,7 +118,7 @@
 		// FIXME: Check if display_id is the default display
 	}
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		if(!libX11)
 		{
 			return success(HEADLESS_DISPLAY);
@@ -174,7 +174,7 @@
 	if(dpy == EGL_NO_DISPLAY && name == EGL_EXTENSIONS)
 	{
 		return success(
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 			"EGL_KHR_platform_gbm "
 			"EGL_KHR_platform_x11 "
 #endif
@@ -1073,7 +1073,7 @@
 {
 	TRACE("(EGLenum platform = 0x%X, void *native_display = %p, const EGLint *attrib_list = %p)", platform, native_display, attrib_list);
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		switch(platform)
 		{
 		case EGL_PLATFORM_X11_EXT: break;
