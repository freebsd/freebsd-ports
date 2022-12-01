--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2022-12-01 10:35:46 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -200,7 +200,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
