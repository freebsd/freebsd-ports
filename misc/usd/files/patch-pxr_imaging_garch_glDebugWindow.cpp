--- pxr/imaging/garch/glDebugWindow.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/imaging/garch/glDebugWindow.cpp
@@ -9,7 +9,7 @@
 #include "pxr/imaging/garch/glPlatformDebugContext.h"
 #include "pxr/base/arch/defines.h"
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_FREEBSD)
 #include "pxr/imaging/garch/glPlatformDebugWindowGLX.h"
 #elif defined(ARCH_OS_DARWIN)
 #include "pxr/imaging/garch/glPlatformDebugWindowDarwin.h"
