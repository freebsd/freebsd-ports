--- cmake/OgreTools.cmake.orig	2018-08-18 08:13:51 UTC
+++ cmake/OgreTools.cmake
@@ -315,7 +315,7 @@ function(vp_set_ogre_media)
     #         the minimal requested media to run the examples
     #--------------
     if(UNIX)
-      set(VISP_INSTALL_DIR_OGRE_RESOURCES "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/visp-${VISP_VERSION}/data/ogre-simulator")
+      set(VISP_INSTALL_DIR_OGRE_RESOURCES "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/visp/data/ogre-simulator")
     else()
       set(VISP_INSTALL_DIR_OGRE_RESOURCES "${CMAKE_INSTALL_PREFIX}/data/ogre-simulator")
     endif()
@@ -341,14 +341,14 @@ function(vp_set_ogre_media)
       )
       install(FILES
         ${VISP_BINARY_DIR}/unix-install/resources.cfg
-        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/visp-${VISP_VERSION}/data/ogre-simulator
+        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/visp/data/ogre-simulator
         PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
         COMPONENT dev
       )
       if(OGRE_MEDIA_NOT_AVAILABLE)
         install(DIRECTORY
           ${VISP_BINARY_DIR}/data/ogre-simulator/media
-          DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/visp-${VISP_VERSION}/data/ogre-simulator
+          DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/visp/data/ogre-simulator
           FILE_PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
           COMPONENT dev
         )
