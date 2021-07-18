--- unittests/unit/test_IkFast.cpp.orig	2021-07-15 08:12:45 UTC
+++ unittests/unit/test_IkFast.cpp
@@ -131,7 +131,7 @@ TEST(IkFast, LoadWamArmIk)
   ik->setHierarchyLevel(1);
   std::stringstream ss;
   ss << DART_SHARED_LIB_PREFIX << "GeneratedWamIkFast";
-#if (DART_OS_LINUX || DART_OS_MACOS) && !NDEBUG
+#if (DART_OS_LINUX || DART_OS_FREEBSD || DART_OS_MACOS) && !NDEBUG
   ss << "d";
 #endif
   ss << "." << DART_SHARED_LIB_EXTENSION;
