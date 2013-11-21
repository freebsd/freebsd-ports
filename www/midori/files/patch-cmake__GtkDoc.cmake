--- ./cmake/GtkDoc.cmake.orig	2013-11-20 01:26:52.000000000 +0000
+++ ./cmake/GtkDoc.cmake	2013-11-21 16:30:38.000000000 +0000
@@ -52,7 +52,7 @@
         file (MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${module}/html")
         gtkdoc_build (${module})
 
-        set (DOC_DIR "html/midori-${MIDORI_MAJOR_VERSION}-${MIDORI_MINOR_VERSION}")
+        set (DOC_DIR "html/midori-${MIDORI_MAJOR_VERSION}.${MIDORI_MINOR_VERSION}")
         install (DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${module}/html/"
             DESTINATION "${CMAKE_INSTALL_DATADIR}/gtk-doc/${DOC_DIR}/${module}"
             PATTERN "html/*"
