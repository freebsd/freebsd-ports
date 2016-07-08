--- cmake/BuildPackages.cmake.orig	2012-05-28 00:21:51.000000000 +0900
+++ cmake/BuildPackages.cmake	2012-05-28 00:22:15.000000000 +0900
@@ -86,5 +86,5 @@
 # Common
 #
 
-install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION doc)
-install(FILES ${CMAKE_SOURCE_DIR}/README.txt DESTINATION doc)
+install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION share/doc/tigervnc)
+install(FILES ${CMAKE_SOURCE_DIR}/README.txt DESTINATION share/doc/tigervnc)
