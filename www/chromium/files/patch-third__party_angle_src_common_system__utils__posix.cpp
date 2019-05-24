--- third_party/angle/src/common/system_utils_posix.cpp.orig	2019-04-30 22:25:51 UTC
+++ third_party/angle/src/common/system_utils_posix.cpp
@@ -17,7 +17,7 @@
 
 // On mac, environ is not declared anywhere:
 // https://stackoverflow.com/a/31347357/912144
-#if defined(ANGLE_PLATFORM_APPLE)
+#if defined(ANGLE_PLATFORM_APPLE) || defined(__FreeBSD__)
 extern char **environ;
 #endif
 
