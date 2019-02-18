--- examples/osgExamples/osgWamIkFast/Helpers.cpp.orig	2018-11-20 05:49:04 UTC
+++ examples/osgExamples/osgWamIkFast/Helpers.cpp
@@ -104,10 +104,10 @@ void setupEndEffectors(const dart::dynam
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
