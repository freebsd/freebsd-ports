--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2020-05-13 18:41:47 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -133,7 +133,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
