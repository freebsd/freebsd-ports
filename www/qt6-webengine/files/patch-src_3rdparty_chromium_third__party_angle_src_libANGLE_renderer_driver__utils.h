--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -179,7 +179,7 @@ inline bool IsLinux()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
