--- cmake/VISPGenerateHeaders.cmake.orig	2017-12-22 17:48:26 UTC
+++ cmake/VISPGenerateHeaders.cmake
@@ -43,7 +43,7 @@ set(VISP_SCENES_DIR ${data_location_}/da
 set(VISP_ROBOT_ARMS_DIR ${data_location_}/data/robot-simulator)
 # Note that VISP_HAVE_OGRE_RESOURCES_PATH and VISP_HAVE_OGRE_PLUGINS_PATH are set in OgreTools.cmake
 if(UNIX)
-  set(data_location_ "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/visp-${VISP_VERSION}")
+  set(data_location_ "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/visp")
 else()
   set(data_location_ "${CMAKE_INSTALL_PREFIX}")
 endif()
@@ -62,7 +62,7 @@ configure_file("${VISP_SOURCE_DIR}/cmake
 
 # case 2: when ViSP is build with make install; files are used in <install dir>
 if(UNIX)
-  set(data_location_ "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/visp-${VISP_VERSION}")
+  set(data_location_ "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/visp")
 else()
   set(data_location_ "${CMAKE_INSTALL_PREFIX}")
 endif()
