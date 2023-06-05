--- cmake/include_libraries.cmake.orig	2023-06-05 12:40:26 UTC
+++ cmake/include_libraries.cmake
@@ -26,4 +26,6 @@ if (ENABLE_SAFEC)
 endif (ENABLE_SAFEC)
 find_package(ICONV QUIET)
 find_package(UUID QUIET)
-find_package(Libunwind)
+if (ENABLE_LIBUNWIND)
+    find_package(Libunwind)
+endif (ENABLE_LIBUNWIND)
