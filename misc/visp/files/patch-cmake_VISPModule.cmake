--- cmake/VISPModule.cmake.orig	2018-08-18 08:13:20 UTC
+++ cmake/VISPModule.cmake
@@ -660,7 +660,7 @@ macro(vp_glob_module_copy_data src dst)
 
     # install
     if(UNIX)
-      set(__install_dst "${CMAKE_INSTALL_DATAROOTDIR}/visp-${VISP_VERSION}/${dst}")
+      set(__install_dst "${CMAKE_INSTALL_DATAROOTDIR}/visp/${dst}")
     else()
       set(__install_dst "${dst}")
     endif()
