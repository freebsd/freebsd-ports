--- third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2021-05-12 22:13:33 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -165,7 +165,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
