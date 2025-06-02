--- cmake_modules/morse_cmake/modules/find/LibrariesAbsolutePath.cmake.orig	2021-06-14 12:08:21 UTC
+++ cmake_modules/morse_cmake/modules/find/LibrariesAbsolutePath.cmake
@@ -55,6 +55,7 @@ macro(LIBRARIES_ABSOLUTE_PATH lib_list hints_paths)
         endif()
       endif()
 
+      if (NOT ${_library} STREQUAL "-pthread")
       # try to find the lib
       find_library(_library_path
         NAMES ${_library}
@@ -66,6 +67,7 @@ macro(LIBRARIES_ABSOLUTE_PATH lib_list hints_paths)
           message(FATAL_ERROR "Dependency of ${lib_list} '${_library}' NOT FOUND")
       endif()
       unset(_library_path CACHE)
+      endif()
     endif()
   endforeach()
 endmacro()
