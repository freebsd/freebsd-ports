--- cmake/FindCheck.cmake.orig	2019-05-31 11:07:23 UTC
+++ cmake/FindCheck.cmake
@@ -23,7 +23,7 @@ INCLUDE( FindPkgConfig )
 PKG_SEARCH_MODULE( CHECK check )
 
 # Look for CHECK include dir and libraries
-IF( NOT CHECK_FOUND )
+#IF( NOT CHECK_FOUND )
     IF ( CHECK_INSTALL_DIR )
         MESSAGE ( STATUS "Using override CHECK_INSTALL_DIR to find check" )
         SET ( CHECK_INCLUDE_DIR  "${CHECK_INSTALL_DIR}/include" )
@@ -50,7 +50,7 @@ IF( NOT CHECK_FOUND )
             ENDIF ( NOT Check_FIND_QUIETLY )
         ENDIF ( Check_FIND_REQUIRED )
     ENDIF ( CHECK_INCLUDE_DIR AND CHECK_LIBRARIES )
-ENDIF( NOT CHECK_FOUND )
+#ENDIF( NOT CHECK_FOUND )
 
 # Hide advanced variables from CMake GUIs
 MARK_AS_ADVANCED( CHECK_INCLUDE_DIR CHECK_LIBRARIES )
