--- cmake/BuildPackages.cmake.orig	2017-05-16 13:53:28 UTC
+++ cmake/BuildPackages.cmake
@@ -86,5 +86,5 @@ endif() #UNIX
 # Common
 #
 
-install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION ${DOC_DIR})
-install(FILES ${CMAKE_SOURCE_DIR}/README.txt DESTINATION ${DOC_DIR})
+install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION share/doc/tigervnc)
+install(FILES ${CMAKE_SOURCE_DIR}/README.txt DESTINATION share/doc/tigervnc)
