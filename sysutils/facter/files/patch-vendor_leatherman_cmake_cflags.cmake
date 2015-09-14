--- vendor/leatherman/cmake/cflags.cmake.orig	2015-07-21 17:31:29 UTC
+++ vendor/leatherman/cmake/cflags.cmake
@@ -2,7 +2,7 @@
 # Each of our project dirs sets CMAKE_CXX_FLAGS based on these. We do
 # not set CMAKE_CXX_FLAGS globally because gtest is not warning-clean.
 if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
-    set(LEATHERMAN_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-tautological-constant-out-of-range-compare")
+    set(LEATHERMAN_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-error")
 
     # Clang warns that 'register' is deprecated; 'register' is used throughout boost, so it can't be an error yet.
     # The warning flag is different on different clang versions so we need to extract the clang version.
@@ -21,6 +21,7 @@ if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL 
     else()
         set(LEATHERMAN_CXX_FLAGS "${LEATHERMAN_CXX_FLAGS} -Wno-deprecated")
     endif()
+    set(LEATHERMAN_LIBRARY_FLAGS "-fPIC")
 elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
     # maybe-uninitialized is a relatively new GCC warning that Boost 1.57 violates; disable it for now until it's available in Clang as well
     # it's also sometimes wrong
