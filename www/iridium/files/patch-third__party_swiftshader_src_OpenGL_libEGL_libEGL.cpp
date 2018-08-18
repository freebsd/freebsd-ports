--- third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp.orig	2018-03-20 23:06:53.000000000 +0100
+++ third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp	2018-03-24 18:42:49.216641000 +0100
@@ -25,7 +25,7 @@
 
 #if defined(__ANDROID__)
 #include <system/window.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "Main/libX11.hpp"
 #endif
 
@@ -119,7 +119,7 @@
 		// FIXME: Check if display_id is the default display
 	}
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		if(!libX11)
 		{
 			return success(HEADLESS_DISPLAY);
@@ -176,7 +176,7 @@
 	{
 		return success(
 			"EGL_KHR_client_get_all_proc_addresses "
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 			"EGL_KHR_platform_gbm "
 			"EGL_KHR_platform_x11 "
 #endif
@@ -944,7 +944,7 @@
 
 	if(context)
 	{
-		#if defined(__linux__) && !defined(__ANDROID__)
+		#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 			egl::Display *display = context->getDisplay();
 
 			if(!display)
@@ -1110,7 +1110,7 @@
 {
 	TRACE("(EGLenum platform = 0x%X, void *native_display = %p, const EGLint *attrib_list = %p)", platform, native_display, attrib_list);
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		switch(platform)
 		{
 		case EGL_PLATFORM_X11_EXT: break;
