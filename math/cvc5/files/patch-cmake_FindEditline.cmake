--- cmake/FindEditline.cmake.orig	2023-01-04 10:29:29 UTC
+++ cmake/FindEditline.cmake
@@ -41,7 +41,7 @@ if(Editline_INCLUDE_DIRS)
   unset(CMAKE_REQUIRED_LIBRARIES)
   unset(CMAKE_REQUIRED_INCLUDES)
 
-  if(NOT CMAKE_SYSTEM_NAME STREQUAL "Darwin")
+  if(FALSE AND NOT CMAKE_SYSTEM_NAME STREQUAL "Darwin")
     set(Editline_LIBRARIES ${Editline_LIBRARIES} bsd tinfo)
   endif()
 endif()
