--- cmake/FindFastFloat.cmake.orig	2024-02-22 15:48:36 UTC
+++ cmake/FindFastFloat.cmake
@@ -2,4 +2,4 @@ target_include_directories(FastFloat::fast_float
 
 target_include_directories(FastFloat::fast_float
     INTERFACE
-        ${TR_THIRD_PARTY_SOURCE_DIR}/fast_float/include)
+    	${CMAKE_INSTALL_PREFIX}/include)
