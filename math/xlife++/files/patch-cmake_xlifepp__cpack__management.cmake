--- cmake/xlifepp_cpack_management.cmake.orig	2018-05-09 16:11:45 UTC
+++ cmake/xlifepp_cpack_management.cmake
@@ -11,7 +11,7 @@ install(FILES "${CMAKE_SOURCE_DIR}/VERSI
         DESTINATION .
         COMPONENT configuration)
 install(DIRECTORY "${CMAKE_SOURCE_DIR}/cmake/"
-        DESTINATION cmake
+        DESTINATION lib/cmake
         COMPONENT configuration
         PATTERN lock.cmake EXCLUDE
         PATTERN guessOS.cmake EXCLUDE
@@ -43,7 +43,7 @@ endif()
 configure_file(${CMAKE_SOURCE_DIR}/etc/templates/getBinaryConfig.cmake.cmake ${CMAKE_BINARY_DIR}/getBinaryConfig.cmake @ONLY)
 
 install(FILES ${CMAKE_BINARY_DIR}/getBinaryConfig.cmake
-        DESTINATION cmake
+        DESTINATION lib/cmake
         COMPONENT configuration)
 
 file(GLOB headers "${CMAKE_SOURCE_DIR}/include/*.h")
@@ -107,7 +107,7 @@ install(FILES "${CMAKE_SOURCE_DIR}/etc/g
         COMPONENT others)
 
 install(DIRECTORY "${CMAKE_SOURCE_DIR}/etc/messages/"
-        DESTINATION etc/messages
+        DESTINATION share/xlife++/messages
         USE_SOURCE_PERMISSIONS
         COMPONENT others)
 
@@ -115,15 +115,15 @@ install(FILES "${CMAKE_SOURCE_DIR}/doc/t
               "${CMAKE_SOURCE_DIR}/doc/tex/dev_documentation.pdf"
               "${CMAKE_SOURCE_DIR}/doc/tex/examples.pdf"
               "${CMAKE_SOURCE_DIR}/doc/tex/tutorial.pdf"
-        DESTINATION share/doc
+        DESTINATION share/doc/xlife++
         COMPONENT documentation)
 
 install(DIRECTORY "${CMAKE_SOURCE_DIR}/examples/"
-        DESTINATION share/examples
+        DESTINATION share/examples/xlife++
         USE_SOURCE_PERMISSIONS
         COMPONENT others)
 install(FILES "${CMAKE_SOURCE_DIR}/usr/main.cpp"
-        DESTINATION share/examples
+        DESTINATION share/examples/xlife++
         COMPONENT others)
 
 install(FILES "${CMAKE_SOURCE_DIR}/tools/visuTermVec.m"
