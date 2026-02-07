--- cmake/xlifepp_cpack_management.cmake.orig	2022-04-22 18:54:13 UTC
+++ cmake/xlifepp_cpack_management.cmake
@@ -10,7 +10,7 @@ install(FILES "${CMAKE_SOURCE_DIR}/VERSION.txt"
         DESTINATION .
         COMPONENT configuration)
 install(DIRECTORY "${CMAKE_SOURCE_DIR}/cmake/"
-        DESTINATION cmake
+        DESTINATION lib/cmake
         COMPONENT configuration
         PATTERN lock.cmake EXCLUDE
         PATTERN guessOS.cmake EXCLUDE
@@ -46,7 +46,7 @@ endif()
 configure_file(${CMAKE_SOURCE_DIR}/etc/templates/getBinaryConfig.cmake.cmake ${CMAKE_BINARY_DIR}/getBinaryConfig.cmake @ONLY)
 
 install(FILES ${CMAKE_BINARY_DIR}/getBinaryConfig.cmake
-        DESTINATION cmake
+        DESTINATION lib/cmake
         COMPONENT configuration)
 
 file(GLOB headers "${CMAKE_SOURCE_DIR}/include/*.h")
@@ -117,7 +117,7 @@ install(FILES "${CMAKE_SOURCE_DIR}/etc/gmsh/xlifepp_ma
         COMPONENT others)
 
 install(DIRECTORY "${CMAKE_SOURCE_DIR}/etc/messages/"
-        DESTINATION etc/messages
+        DESTINATION share/xlife++/messages
         USE_SOURCE_PERMISSIONS
         COMPONENT others)
 
@@ -125,15 +125,15 @@ install(FILES "${CMAKE_SOURCE_DIR}/doc/tex/user_docume
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
 
 install(FILES "${CMAKE_SOURCE_DIR}/etc/visuTermVec.m"
