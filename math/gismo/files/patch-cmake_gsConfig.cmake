- -no-sse2 flag is added by cmake: https://github.com/gismo/gismo/issues/570
- this triggers the clang crash: https://bugs.llvm.org/show_bug.cgi?id=51468

--- cmake/gsConfig.cmake.orig	2022-12-12 19:15:56 UTC
+++ cmake/gsConfig.cmake
@@ -263,7 +263,7 @@ endif()
 #string(TOUPPER ${CMAKE_BUILD_TYPE} TEMP)
 #message(STATUS "Using compilation flags: ${CMAKE_CXX_FLAGS}, ${CMAKE_CXX_FLAGS_${TEMP}}")
 
-if("x${CMAKE_BUILD_TYPE}" STREQUAL "xRelease")
+if(FALSE AND "x${CMAKE_BUILD_TYPE}" STREQUAL "xRelease")
   #https://github.com/VcDevel/Vc/blob/master/cmake/OptimizeForArchitecture.cmake
   include( OptimizeForArchitecture )
   OptimizeForArchitecture()
