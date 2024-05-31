--- cmake/FindUtfCpp.cmake.orig	2024-02-22 15:49:05 UTC
+++ cmake/FindUtfCpp.cmake
@@ -2,4 +2,4 @@ target_include_directories(utf8::cpp
 
 target_include_directories(utf8::cpp
     INTERFACE
-     ${CMAKE_CURRENT_LIST_DIR}/../third-party/utfcpp/source)
+    	${CMAKE_INSTALL_PREFIX}/include/utf8cpp)
