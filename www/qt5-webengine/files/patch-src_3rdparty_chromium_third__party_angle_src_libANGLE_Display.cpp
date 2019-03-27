--- src/3rdparty/chromium/third_party/angle/src/libANGLE/Display.cpp.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/Display.cpp
@@ -63,7 +63,7 @@
 #if defined(ANGLE_ENABLE_VULKAN)
 #if defined(ANGLE_PLATFORM_WINDOWS)
 #include "libANGLE/renderer/vulkan/win32/DisplayVkWin32.h"
-#elif defined(ANGLE_PLATFORM_LINUX)
+#elif defined(ANGLE_PLATFORM_POSIX)
 #include "libANGLE/renderer/vulkan/xcb/DisplayVkXcb.h"
 #elif defined(ANGLE_PLATFORM_ANDROID)
 #include "libANGLE/renderer/vulkan/android/DisplayVkAndroid.h"
@@ -211,7 +211,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(const Attrib
 #if defined(ANGLE_ENABLE_VULKAN)
 #if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayVkWin32(state);
-#elif defined(ANGLE_PLATFORM_LINUX)
+#elif defined(ANGLE_PLATFORM_POSIX)
             impl = new rx::DisplayVkXcb(state);
 #elif defined(ANGLE_PLATFORM_ANDROID)
             impl = new rx::DisplayVkAndroid(state);
