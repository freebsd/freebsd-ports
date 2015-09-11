--- vendor/leatherman/cmake/cflags.cmake.orig	2015-07-21 17:31:29 UTC
+++ vendor/leatherman/cmake/cflags.cmake
@@ -21,6 +21,7 @@ if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL 
     else()
         set(LEATHERMAN_CXX_FLAGS "${LEATHERMAN_CXX_FLAGS} -Wno-deprecated")
     endif()
+    set(LEATHERMAN_LIBRARY_FLAGS "-fPIC")
 elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
     # maybe-uninitialized is a relatively new GCC warning that Boost 1.57 violates; disable it for now until it's available in Clang as well
     # it's also sometimes wrong
