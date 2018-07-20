--- cmake/BuildPackages.cmake.orig	2017-04-19 13:27:31 UTC
+++ cmake/BuildPackages.cmake
@@ -86,5 +86,5 @@ endif() #UNIX
 # Common
 #
 
-install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION ${DOC_DIR})
-install(FILES ${CMAKE_SOURCE_DIR}/README.rst DESTINATION ${DOC_DIR})
+install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION share/doc/tigervnc)
+install(FILES ${CMAKE_SOURCE_DIR}/README.rst DESTINATION share/doc/tigervnc)
