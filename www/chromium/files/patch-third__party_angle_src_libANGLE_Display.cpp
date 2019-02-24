--- third_party/angle/src/libANGLE/Display.cpp.orig	2019-01-30 02:20:31.000000000 +0100
+++ third_party/angle/src/libANGLE/Display.cpp	2019-02-01 11:09:24.980814000 +0100
@@ -63,7 +63,7 @@
 #if defined(ANGLE_ENABLE_VULKAN)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
 #        include "libANGLE/renderer/vulkan/win32/DisplayVkWin32.h"
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        include "libANGLE/renderer/vulkan/xcb/DisplayVkXcb.h"
 #    elif defined(ANGLE_PLATFORM_ANDROID)
 #        include "libANGLE/renderer/vulkan/android/DisplayVkAndroid.h"
@@ -215,7 +215,7 @@
 #if defined(ANGLE_ENABLE_VULKAN)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayVkWin32(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
             impl = new rx::DisplayVkXcb(state);
 #    elif defined(ANGLE_PLATFORM_ANDROID)
             impl = new rx::DisplayVkAndroid(state);
