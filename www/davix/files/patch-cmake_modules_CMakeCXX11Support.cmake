- https://github.com/cern-fts/davix/issues/132

--- cmake/modules/CMakeCXX11Support.cmake.orig	2025-01-22 08:00:31 UTC
+++ cmake/modules/CMakeCXX11Support.cmake
@@ -13,7 +13,7 @@ if(CMAKE_COMPILER_IS_GNUCXX)
    elseif(GCC_VERSION VERSION_GREATER 4.3 OR GCC_VERSION VERSION_EQUAL 4.3)
         message(STATUS "C++11 partial support")
 		SET(HAVE_CXX011_PARTIAL_SUPPORT TRUE)
-                SET(CXX11_FLAG_ENABLE "-std=c++0x")
+                SET(CXX11_FLAG_ENABLE "-std=c++14")
    else ()
         message(STATUS "C++11 no support ")
         SET(CXX11_FLAG_ENABLE "")
@@ -22,7 +22,7 @@ else(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "C++11 activated full")
    SET(HAVE_CXX011_FULL_SUPPORT TRUE)
    SET(HAVE_CXX011_PARTIAL_SUPPORT TRUE)
-   SET(CXX11_FLAG_ENABLE "-std=c++0x")
+   SET(CXX11_FLAG_ENABLE "-std=c++14")
 endif(CMAKE_COMPILER_IS_GNUCXX)
 
 ## Check TR1
