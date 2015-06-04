--- Resources/CMake/SQLiteConfiguration.cmake.orig	2015-02-12 13:47:38 UTC
+++ Resources/CMake/SQLiteConfiguration.cmake
@@ -28,8 +28,11 @@ else()
     message(FATAL_ERROR "Please install the libsqlite3-dev package")
   endif()
 
+  find_path(SQLITE_INCLUDE_DIR sqlite3.h)
+  message("SQLite include dir: ${SQLITE_INCLUDE_DIR}")
+
   # Autodetection of the version of SQLite
-  file(STRINGS "/usr/include/sqlite3.h" SQLITE_VERSION_NUMBER1 REGEX "#define SQLITE_VERSION_NUMBER.*$")    
+  file(STRINGS "${SQLITE_INCLUDE_DIR}/sqlite3.h" SQLITE_VERSION_NUMBER1 REGEX "#define SQLITE_VERSION_NUMBER.*$")
   string(REGEX REPLACE "#define SQLITE_VERSION_NUMBER(.*)$" "\\1" SQLITE_VERSION_NUMBER ${SQLITE_VERSION_NUMBER1})
 
   message("Detected version of SQLite: ${SQLITE_VERSION_NUMBER}")
