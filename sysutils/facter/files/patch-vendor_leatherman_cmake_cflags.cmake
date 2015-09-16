--- vendor/leatherman/cmake/cflags.cmake.orig	2015-09-14 20:07:07 UTC
+++ vendor/leatherman/cmake/cflags.cmake
@@ -2,7 +2,7 @@
 # Each of our project dirs sets CMAKE_CXX_FLAGS based on these. We do
 # not set CMAKE_CXX_FLAGS globally because gtest is not warning-clean.
 if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "\\w*Clang")
-    set(LEATHERMAN_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-tautological-constant-out-of-range-compare")
+    set(LEATHERMAN_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-error")
 
     # Clang warns that 'register' is deprecated; 'register' is used throughout boost, so it can't be an error yet.
     # The warning flag is different on different clang versions so we need to extract the clang version.
