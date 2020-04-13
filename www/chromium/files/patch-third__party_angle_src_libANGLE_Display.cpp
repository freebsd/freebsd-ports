--- third_party/angle/src/libANGLE/Display.cpp.orig	2020-03-16 18:42:05 UTC
+++ third_party/angle/src/libANGLE/Display.cpp
@@ -286,7 +286,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
             {
                 impl = rx::CreateVulkanWin32Display(state);
             }
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
             if (rx::IsVulkanXcbDisplayAvailable())
             {
                 impl = rx::CreateVulkanXcbDisplay(state);
