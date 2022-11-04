- workaround for https://github.com/BlueBrain/HighFive/issues/633

--- CMake/HighFiveTargetDeps.cmake.orig	2022-11-04 06:45:25 UTC
+++ CMake/HighFiveTargetDeps.cmake
@@ -8,7 +8,7 @@ if(NOT TARGET libdeps)
 
   # HDF5
   if(NOT DEFINED HDF5_C_LIBRARIES)
-    set(HDF5_NO_FIND_PACKAGE_CONFIG_FILE TRUE)  # Consistency
+    #set(HDF5_NO_FIND_PACKAGE_CONFIG_FILE TRUE)  # Consistency
     set(HDF5_PREFER_PARALLEL ${HIGHFIVE_PARALLEL_HDF5})
     find_package(HDF5 REQUIRED)
   endif()
