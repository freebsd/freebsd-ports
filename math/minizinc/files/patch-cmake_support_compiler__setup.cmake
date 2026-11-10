-- fix compilation breakage due to use of C++14 features
-- upstreamed: https://github.com/MiniZinc/libminizinc/issues/1103

--- cmake/support/compiler_setup.cmake.orig	2026-11-10 20:51:55 UTC
+++ cmake/support/compiler_setup.cmake
@@ -1,4 +1,4 @@
-set(CMAKE_CXX_STANDARD 11)
+set(CMAKE_CXX_STANDARD 14)
 
 if(WIN32)
   # _WIN32_WINNT is set for <Windows.h> such that the Vista+ process APIs used
