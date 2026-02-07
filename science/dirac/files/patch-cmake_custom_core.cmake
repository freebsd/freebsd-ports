--- cmake/custom/core.cmake.orig	2022-08-10 16:56:44 UTC
+++ cmake/custom/core.cmake
@@ -101,7 +101,7 @@ foreach(
     if(${CMAKE_SYSTEM_NAME} STREQUAL "AIX")
         SET_TARGET_PROPERTIES(${_executable} PROPERTIES LINK_FLAGS "-Wl,-bbigtoc")
     endif()
-    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
+    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
         SET_TARGET_PROPERTIES(${_executable} PROPERTIES LINK_FLAGS "-Wl,-E")
     endif()
 
