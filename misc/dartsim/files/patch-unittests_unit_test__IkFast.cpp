--- unittests/unit/test_IkFast.cpp.orig	2018-11-20 05:49:54 UTC
+++ unittests/unit/test_IkFast.cpp
@@ -74,10 +74,10 @@ TEST(IkFast, LoadWamArmIk)
   ik->setTarget(targetFrame);
   ik->setHierarchyLevel(1);
   std::string libName = "libGeneratedWamIkFast";
-#if (DART_OS_LINUX || DART_OS_MACOS) && !NDEBUG
+#if (DART_OS_LINUX || DART_OS_FREEBSD || DART_OS_MACOS) && !NDEBUG
   libName += "d";
 #endif
-#if DART_OS_LINUX
+#if DART_OS_LINUX || DART_OS_FREEBSD
   libName += ".so";
 #elif DART_OS_MACOS
   libName += ".dylib";
