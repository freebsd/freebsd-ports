--- Source/ThirdParty/ANGLE/src/common/SimpleMutex.h.orig	2024-08-19 06:28:35 UTC
+++ Source/ThirdParty/ANGLE/src/common/SimpleMutex.h
@@ -42,6 +42,9 @@
 // Assume support.
 #        define ANGLE_USE_FUTEX 1
 #    endif  // defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_ANDROID)
+#    if defined(ANGLE_PLATFORM_FREEBSD) || defined(ANGLE_PLATFORM_OPENBSD)
+#        define ANGLE_USE_FUTEX 0
+#    endif
 #endif      // !defined(ANGLE_WITH_TSAN)
 
 namespace angle
