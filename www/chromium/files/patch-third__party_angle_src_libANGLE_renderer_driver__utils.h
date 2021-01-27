--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2021-01-18 21:31:44 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -151,7 +151,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
