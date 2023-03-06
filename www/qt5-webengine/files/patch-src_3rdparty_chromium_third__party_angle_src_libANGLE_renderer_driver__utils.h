--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -145,7 +145,7 @@ inline bool IsLinux()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
