--- third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp.orig	2020-03-03 18:55:29 UTC
+++ third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp
@@ -153,7 +153,7 @@ EGLDisplay EGLAPIENTRY GetDisplay(EGLNativeDisplayType
 		// FIXME: Check if display_id is the default display
 	}
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD)) && !defined(__ANDROID__)
 		#if defined(USE_X11)
 		if(!libX11)
 		#endif  // Non X11 linux is headless only
@@ -216,7 +216,7 @@ const char *EGLAPIENTRY QueryString(EGLDisplay dpy, EG
 	{
 		return success(
 			"EGL_KHR_client_get_all_proc_addresses "
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 			"EGL_KHR_platform_gbm "
 #endif
 #if defined(USE_X11)
@@ -1298,7 +1298,7 @@ EGLDisplay EGLAPIENTRY GetPlatformDisplay(EGLenum plat
 {
 	TRACE("(EGLenum platform = 0x%X, void *native_display = %p, const EGLAttrib *attrib_list = %p)", platform, native_display, attrib_list);
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		switch(platform)
 		{
 		#if defined(USE_X11)
