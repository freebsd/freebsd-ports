--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2019-12-16 21:56:11 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -115,7 +115,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
