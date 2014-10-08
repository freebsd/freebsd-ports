--- CMake/install.cmake.orig	2014-09-27 02:41:06.000000000 +0200
+++ CMake/install.cmake	2014-10-08 14:32:55.000000000 +0200
@@ -32,7 +32,7 @@
 )
 
 install(DIRECTORY ${FLTK_SOURCE_DIR}/FL
-   DESTINATION include USE_SOURCE_PERMISSIONS
+   DESTINATION include/fltk-devel USE_SOURCE_PERMISSIONS
    PATTERN ".svn" EXCLUDE
 )
 
@@ -75,7 +75,7 @@
    install(FILES
       ${FLTK_SOURCE_DIR}/documentation/src/${FILE}.man
       DESTINATION man/man${LEVEL}
-      RENAME ${FILE}.${LEVEL}
+      RENAME ${FILE}-devel.${LEVEL}
    )
    endmacro(INSTALL_MAN FILE LEVEL)
 
