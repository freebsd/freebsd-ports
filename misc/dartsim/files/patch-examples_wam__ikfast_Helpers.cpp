--- examples/wam_ikfast/Helpers.cpp.orig	2021-07-15 08:12:45 UTC
+++ examples/wam_ikfast/Helpers.cpp
@@ -109,7 +109,7 @@ void setupEndEffectors(const dart::dynamics::SkeletonP
 
   std::stringstream ss;
   ss << DART_SHARED_LIB_PREFIX << "wamIk";
-#if (DART_OS_LINUX || DART_OS_MACOS) && !NDEBUG
+#if (DART_OS_LINUX || DART_OS_FREEBSD || DART_OS_MACOS) && !NDEBUG
   ss << "d";
 #endif
   ss << "." << DART_SHARED_LIB_EXTENSION;
