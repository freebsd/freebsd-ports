--- third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp.orig	2018-12-15 16:34:59.695784000 +0100
+++ third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp	2018-12-15 16:37:11.859379000 +0100
@@ -148,7 +148,7 @@
 		// FIXME: Check if display_id is the default display
 	}
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD)) && !defined(__ANDROID__)
 		#if defined(USE_X11)
 		if(!libX11)
 		#endif  // Non X11 linux is headless only
@@ -207,7 +207,7 @@
 	{
 		return success(
 			"EGL_KHR_client_get_all_proc_addresses "
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 			"EGL_KHR_platform_gbm "
 #endif
 #if defined(USE_X11)
@@ -1248,7 +1248,7 @@
 {
 	TRACE("(EGLenum platform = 0x%X, void *native_display = %p, const EGLAttrib *attrib_list = %p)", platform, native_display, attrib_list);
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		switch(platform)
 		{
 		#if defined(USE_X11)
