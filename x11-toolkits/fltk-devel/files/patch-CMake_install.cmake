--- CMake/install.cmake.orig	2014-02-14 15:10:59.000000000 +0100
+++ CMake/install.cmake	2014-02-14 15:11:07.000000000 +0100
@@ -63,7 +63,7 @@
    install(FILES
       ${FLTK_SOURCE_DIR}/documentation/src/${FILE}.man
       DESTINATION ${PREFIX_MAN}/man${LEVEL}
-      RENAME ${FILE}.${LEVEL}
+      RENAME ${FILE}-devel.${LEVEL}
    )
    endmacro(INSTALL_MAN FILE LEVEL)
 
