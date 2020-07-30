--- third_party/angle/src/libANGLE/Display.cpp.orig	2020-07-07 22:03:18 UTC
+++ third_party/angle/src/libANGLE/Display.cpp
@@ -54,7 +54,7 @@
 #        include "libANGLE/renderer/gl/cgl/DisplayCGL.h"
 #    elif defined(ANGLE_PLATFORM_IOS)
 #        include "libANGLE/renderer/gl/eagl/DisplayEAGL.h"
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_OZONE)
 #            include "libANGLE/renderer/gl/egl/ozone/DisplayOzone.h"
 #        else
@@ -252,7 +252,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
             impl = new rx::DisplayCGL(state);
 #    elif defined(ANGLE_PLATFORM_IOS)
             impl = new rx::DisplayEAGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_OZONE)
             // This might work but has never been tried, so disallow for now.
             impl = nullptr;
@@ -284,7 +284,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
 #if defined(ANGLE_ENABLE_OPENGL)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayWGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_OZONE)
             impl = new rx::DisplayOzone(state);
 #        else
@@ -315,7 +315,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
             {
                 impl = rx::CreateVulkanWin32Display(state);
             }
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
             if (rx::IsVulkanXcbDisplayAvailable())
             {
                 impl = rx::CreateVulkanXcbDisplay(state);
@@ -1395,7 +1395,7 @@ static ClientExtensions GenerateClientExtensions()
     extensions.x11Visual = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX) && !defined(ANGLE_USE_OZONE)
+#if defined(ANGLE_PLATFORM_POSIX) && !defined(ANGLE_USE_OZONE)
     extensions.platformANGLEDeviceTypeEGLANGLE = true;
 #endif
 
