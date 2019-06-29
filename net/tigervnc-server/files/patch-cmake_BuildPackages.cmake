--- cmake/BuildPackages.cmake.orig	2018-07-16 14:08:55 UTC
+++ cmake/BuildPackages.cmake
@@ -86,5 +86,3 @@ endif() #UNIX
 # Common
 #
 
-install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION ${DOC_DIR})
-install(FILES ${CMAKE_SOURCE_DIR}/README.rst DESTINATION ${DOC_DIR})
