--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -173,7 +173,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
