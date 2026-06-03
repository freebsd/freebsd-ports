--- cmake/tpl/boost.cmake.orig	2025-10-30 22:36:06 UTC
+++ cmake/tpl/boost.cmake
@@ -1,3 +1,3 @@ if (NOT BOOST_HEADER_ONLY)
 if (NOT BOOST_HEADER_ONLY)
-  set(${lib_name}_libs libboost_filesystem.so libboost_system.so)
+  set(${lib_name}_libs libboost_filesystem.so)
 endif()
