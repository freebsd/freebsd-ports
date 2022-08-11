--- source/gfx/gfx-opengl.cpp.orig	2022-06-19 17:00:46 UTC
+++ source/gfx/gfx-opengl.cpp
@@ -28,7 +28,7 @@
 #ifdef D_PLATFORM_WINDOWS
 #include "glad/wgl.h"
 #endif
-#ifdef D_PLATFORM_LINUX
+#if defined(D_PLATFORM_LINUX) || defined(D_PLATFORM_FREEBSD)
 #include "glad/glx.h"
 #endif
 
@@ -67,7 +67,7 @@ streamfx::gfx::opengl::opengl()
 	// ToDo: Figure out the HDC for which we need to load.
 	//gladLoaderLoadWGL();
 #endif
-#ifdef D_PLATFORM_LINUX
+#if defined(D_PLATFORM_LINUX) || defined(D_PLATFORM_FREEBSD)
 	//gladLoaderLoadGLX();
 #endif // D_PLATFORM_LINUX
 	D_LOG_INFO("Version %d.%d initialized.", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
@@ -80,7 +80,7 @@ streamfx::gfx::opengl::~opengl()
 	// Does not appear to exist.
 	//gladLoaderUnloadWGL();
 #endif
-#ifdef D_PLATFORM_LINUX
+#if defined(D_PLATFORM_LINUX) || defined(D_PLATFORM_FREEBSD)
 	//gladLoaderUnloadGLX();
 #endif
 	D_LOG_INFO("Finalized.", "");
