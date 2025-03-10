--- cmake/modules/FindHDF5.cmake.orig	2024-08-25 02:15:46 UTC
+++ cmake/modules/FindHDF5.cmake
@@ -22,7 +22,7 @@ if(NOT HDF5_INCLUDEDIR)
   endif()
 
   if(HDF5_INCLUDEDIR AND HDF5_LIBRARIES)
-    FIND_LIBRARY(HDF5_LIBRARY_CPP hdf5_c++
+    FIND_LIBRARY(HDF5_LIBRARY_CPP hdf5_c++ hdf5_cpp
       HINTS ${HDF5_LIBRARY_DIRS})
     set(HDF5_LIBRARY_C -L${HDF5_LIBRARY_DIRS} ${HDF5_LIBRARIES} CACHE STRING "" FORCE)
   else()
