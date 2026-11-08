--- cmake/custom/core.cmake.orig	2026-04-10 17:09:54 UTC
+++ cmake/custom/core.cmake
@@ -88,7 +88,7 @@ foreach(
     if(${CMAKE_SYSTEM_NAME} STREQUAL "AIX")
         SET_TARGET_PROPERTIES(${_executable} PROPERTIES LINK_FLAGS "-Wl,-bbigtoc")
     endif()
-    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
+    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
         SET_TARGET_PROPERTIES(${_executable} PROPERTIES LINK_FLAGS "-Wl,-E")
     endif()
 
