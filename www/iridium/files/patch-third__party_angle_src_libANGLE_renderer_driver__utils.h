--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2023-07-24 14:27:53 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -212,7 +212,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
