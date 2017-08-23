--- third_party/angle/src/libANGLE/Display.cpp.orig	2017-08-02 15:04:04.122103000 +0200
+++ third_party/angle/src/libANGLE/Display.cpp	2017-08-02 15:04:56.343338000 +0200
@@ -61,7 +61,7 @@
 #if defined(ANGLE_ENABLE_VULKAN)
 #if defined(ANGLE_PLATFORM_WINDOWS)
 #include "libANGLE/renderer/vulkan/win32/DisplayVkWin32.h"
-#elif defined(ANGLE_PLATFORM_LINUX)
+#elif defined(ANGLE_PLATFORM_POSIX)
 #include "libANGLE/renderer/vulkan/xcb/DisplayVkXcb.h"
 #else
 #error Unsupported Vulkan platform.
@@ -207,7 +207,7 @@
 #if defined(ANGLE_ENABLE_VULKAN)
 #if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayVkWin32(state);
-#elif defined(ANGLE_PLATFORM_LINUX)
+#elif defined(ANGLE_PLATFORM_POSIX)
             impl = new rx::DisplayVkXcb(state);
 #else
 #error Unsupported Vulkan platform.
