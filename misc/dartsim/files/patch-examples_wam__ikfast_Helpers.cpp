--- examples/wam_ikfast/Helpers.cpp.orig	2019-08-17 03:14:11 UTC
+++ examples/wam_ikfast/Helpers.cpp
@@ -106,10 +106,10 @@ void setupEndEffectors(const dart::dynamics::SkeletonP
   ee->getIK(true)->setTarget(wam7_target);
 
   std::string libName = "libwamIk";
-#if (DART_OS_LINUX || DART_OS_MACOS) && !NDEBUG
+#if (DART_OS_LINUX || DART_OS_FREEBSD || DART_OS_MACOS) && !NDEBUG
   libName += "d";
 #endif
-#if DART_OS_LINUX
+#if DART_OS_LINUX || DART_OS_FREEBSD
   libName += ".so";
 #elif DART_OS_MACOS
   libName += ".dylib";
