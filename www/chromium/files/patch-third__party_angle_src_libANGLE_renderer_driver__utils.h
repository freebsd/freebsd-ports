--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2021-04-14 18:42:58 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -158,7 +158,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
