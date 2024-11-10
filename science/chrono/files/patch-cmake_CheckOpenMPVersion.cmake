--- cmake/CheckOpenMPVersion.cmake.orig	2024-11-10 17:32:43 UTC
+++ cmake/CheckOpenMPVersion.cmake
@@ -7,7 +7,6 @@ include(CheckCXXSourceCompiles)
 include(CheckCXXSourceCompiles)
 
 # Set compiler flag to generate instructions for the host architecture.
-set(CMAKE_REQUIRED_FLAGS "-march=native")
 
 # Assume at least 2.0 support
 SET(OMP_VERSION "2.0")
