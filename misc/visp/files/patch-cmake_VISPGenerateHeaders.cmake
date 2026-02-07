--- cmake/VISPGenerateHeaders.cmake.orig	2021-02-26 14:57:15 UTC
+++ cmake/VISPGenerateHeaders.cmake
@@ -58,7 +58,7 @@ configure_file("${VISP_SOURCE_DIR}/cmake/templates/vpC
 
 # case 2: when ViSP is build with make install; files are used in <install dir>
 if(UNIX)
-  set(data_location_ "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/visp-${VISP_VERSION}")
+  set(data_location_ "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/visp")
 else()
   set(data_location_ "${CMAKE_INSTALL_PREFIX}")
 endif()
