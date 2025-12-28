--- cmake/find_z3.cmake.orig	2025-12-23 15:04:53 UTC
+++ cmake/find_z3.cmake
@@ -31,11 +31,6 @@ if (ENABLE_SOLVER_Z3)
     message(STATUS "Found Z3")
     set(ENABLE_Z3 1) # For config.h
 
-    # Check the signature of `Z3_get_error_msg()`
-    cmake_push_check_state()
-    set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} ${Z3_INCLUDE_DIRS})
-    set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} ${Z3_LIBRARIES})
-
     if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
       string(REPLACE ".so" ".dylib" Z3_LIBRARIES ${Z3_LIBRARIES})
       message(STATUS "New Z3 library path: ${Z3_LIBRARIES}")
