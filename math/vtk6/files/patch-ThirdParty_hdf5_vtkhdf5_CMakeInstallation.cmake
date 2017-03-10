So that this port doesn't clash with science/paraview:

--- ThirdParty/hdf5/vtkhdf5/CMakeInstallation.cmake.orig	2017-01-20 17:51:20 UTC
+++ ThirdParty/hdf5/vtkhdf5/CMakeInstallation.cmake
@@ -105,11 +105,6 @@ configure_file (
     ${HDF5_RESOURCES_DIR}/libhdf5.settings.cmake.in 
     ${HDF5_BINARY_DIR}/libhdf5.settings @ONLY
 )
-install (
-    FILES ${HDF5_BINARY_DIR}/libhdf5.settings
-    DESTINATION ${HDF5_INSTALL_CMAKE_DIR}/${HDF5_PACKAGE}
-    COMPONENT libraries
-)
 
 #-----------------------------------------------------------------------------
 # Configure the HDF518_Examples.cmake file and the examples
