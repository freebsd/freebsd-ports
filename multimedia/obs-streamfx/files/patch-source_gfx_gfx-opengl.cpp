--- source/gfx/gfx-opengl.cpp.orig	2022-12-02 04:28:08 UTC
+++ source/gfx/gfx-opengl.cpp
@@ -32,7 +32,7 @@
 #ifdef D_PLATFORM_WINDOWS
 #include "glad/wgl.h"
 #endif
-#ifdef D_PLATFORM_LINUX
+#if defined(D_PLATFORM_LINUX) || defined(D_PLATFORM_FREEBSD)
 #include "glad/glx.h"
 #endif
 #include "warning-enable.hpp"
@@ -72,7 +72,7 @@ streamfx::gfx::opengl::opengl()
 	// ToDo: Figure out the HDC for which we need to load.
 	//gladLoaderLoadWGL();
 #endif
-#ifdef D_PLATFORM_LINUX
+#if defined(D_PLATFORM_LINUX) || defined(D_PLATFORM_FREEBSD)
 	//gladLoaderLoadGLX();
 #endif // D_PLATFORM_LINUX
 	D_LOG_INFO("Version %d.%d initialized.", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
@@ -85,7 +85,7 @@ streamfx::gfx::opengl::~opengl()
 	// Does not appear to exist.
 	//gladLoaderUnloadWGL();
 #endif
-#ifdef D_PLATFORM_LINUX
+#if defined(D_PLATFORM_LINUX) || defined(D_PLATFORM_FREEBSD)
 	//gladLoaderUnloadGLX();
 #endif
 	D_LOG_INFO("Finalized.", "");
