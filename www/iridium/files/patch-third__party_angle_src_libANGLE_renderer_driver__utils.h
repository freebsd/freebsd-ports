--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2022-03-28 18:11:04 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -179,7 +179,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
