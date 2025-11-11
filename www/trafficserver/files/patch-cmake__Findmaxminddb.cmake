--- cmake/Findmaxminddb.cmake.orig	2025-01-29 14:00:25 UTC
+++ cmake/Findmaxminddb.cmake
@@ -31,6 +31,8 @@
 # maxminddb exports their own config since maxminddb-1.5.0, but it isn't
 # present in the OpenSUSE libmaxminddb-devel-1.7.1 package and maybe others.
 
+if(BUILD_MAXMIND_ACL)
+
 find_library(maxminddb_LIBRARY NAMES maxminddb)
 find_path(maxminddb_INCLUDE_DIR NAMES maxminddb.h)
 
@@ -47,4 +49,6 @@ if(maxminddb_FOUND AND NOT TARGET maxminddb::maxminddb
   add_library(maxminddb::maxminddb INTERFACE IMPORTED)
   target_include_directories(maxminddb::maxminddb INTERFACE ${maxminddb_INCLUDE_DIRS})
   target_link_libraries(maxminddb::maxminddb INTERFACE "${maxminddb_LIBRARY}")
+endif()
+
 endif()
