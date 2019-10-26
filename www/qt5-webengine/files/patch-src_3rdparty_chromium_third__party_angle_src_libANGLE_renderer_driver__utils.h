--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -107,7 +107,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
