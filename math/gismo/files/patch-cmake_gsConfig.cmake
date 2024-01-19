- -no-sse2 flag is added by cmake: https://github.com/gismo/gismo/issues/570
- this triggers the clang crash: https://bugs.llvm.org/show_bug.cgi?id=51468

--- cmake/gsConfig.cmake.orig	2023-12-31 16:59:24 UTC
+++ cmake/gsConfig.cmake
@@ -270,7 +270,7 @@ endif()
 #string(TOUPPER ${CMAKE_BUILD_TYPE} TEMP)
 #message(STATUS "Using compilation flags: ${CMAKE_CXX_FLAGS}, ${CMAKE_CXX_FLAGS_${TEMP}}")
 
-if("x${CMAKE_BUILD_TYPE}" STREQUAL "xRelease" AND NOT ARCHITECTURE_CXX_FLAGS)
+if(FALSE AND "x${CMAKE_BUILD_TYPE}" STREQUAL "xRelease" AND NOT ARCHITECTURE_CXX_FLAGS)
   include( OptimizeForArchitecture )
   OptimizeForArchitecture()
   foreach (flag ${ARCHITECTURE_CXX_FLAGS})
