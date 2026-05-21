--- src/3rdparty/chromium/third_party/angle/src/common/platform_helpers.h.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/third_party/angle/src/common/platform_helpers.h
@@ -62,7 +62,7 @@ inline constexpr bool IsIOS()
 
 inline constexpr bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
