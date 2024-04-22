--- cmake/include_libraries.cmake.orig	2024-02-20 18:54:47 UTC
+++ cmake/include_libraries.cmake
@@ -26,6 +26,8 @@ find_package(UUID QUIET)
 endif (ENABLE_SAFEC)
 find_package(ICONV QUIET)
 find_package(UUID QUIET)
-find_package(Libunwind)
+if (ENABLE_LIBUNWIND)
+    find_package(Libunwind)
+endif (ENABLE_LIBUNWIND)
 find_package(NUMA QUIET)
 find_package(ML QUIET)
