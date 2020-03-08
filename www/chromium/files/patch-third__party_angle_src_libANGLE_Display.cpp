--- third_party/angle/src/libANGLE/Display.cpp.orig	2020-03-03 18:55:22 UTC
+++ third_party/angle/src/libANGLE/Display.cpp
@@ -269,7 +269,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(const Attrib
             {
                 impl = rx::CreateVulkanWin32Display(state);
             }
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
             if (rx::IsVulkanXcbDisplayAvailable())
             {
                 impl = rx::CreateVulkanXcbDisplay(state);
