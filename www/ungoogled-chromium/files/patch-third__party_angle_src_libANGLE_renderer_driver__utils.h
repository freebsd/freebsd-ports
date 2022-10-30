--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2022-10-29 17:50:56 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -200,7 +200,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
