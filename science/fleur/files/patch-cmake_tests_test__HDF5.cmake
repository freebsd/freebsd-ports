--- cmake/tests/test_HDF5.cmake.orig	2018-07-03 14:37:33 UTC
+++ cmake/tests/test_HDF5.cmake
@@ -1,6 +1,6 @@
 #first try if hdf already works
 try_compile(FLEUR_USE_HDF5 ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_HDF5.f90
-	    LINK_LIBRARIES ${FLEUR_LIBRARIES}
+	    LINK_LIBRARIES ${FLEUR_LIBRARIES} -lhdf5
             )
 #now try to find the library using HDF5_ROOT variable
 if (NOT FLEUR_USE_HDF5)
@@ -15,7 +15,7 @@ if (NOT FLEUR_USE_HDF5)
         set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -I${HDF5_INCLUDE}")
      endif()
 	try_compile(FLEUR_USE_HDF5 ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_HDF5.f90
-   	    LINK_LIBRARIES ${TEST_LIBRARIES}
+   	    LINK_LIBRARIES ${TEST_LIBRARIES} -lhdf5
             )
        if (NOT FLEUR_USE_HDF5)
 	       set(CMAKE_Fortran_FLAGS ${STORE_FLAGS})
@@ -35,7 +35,7 @@ if (NOT FLEUR_USE_HDF5)
           set(CMAKE_Fortran_FLAGS "-I${HDF5_INCLUDE_LIBRARIES}" ${CMAKE_Fortran_FLAGS})
 
 try_compile(FLEUR_USE_HDF5 ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_HDF5.f90
-            LINK_LIBRARIES ${TEST_LIBRARIES}
+            LINK_LIBRARIES ${TEST_LIBRARIES} -lhdf5
             )
 	    if (${FLEUR_USE_HDF5})
 	       set(FLEUR_LIBRARIES ${HDF5_Fortran_LIBRARIES} ${FLEUR_LIBRARIES})
@@ -49,14 +49,14 @@ endif()       
 #check if HDF is parallel
 if ( FLEUR_USE_HDF5)
    try_compile(FLEUR_USE_HDF5MPI ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_HDF5MPI.f90
-            LINK_LIBRARIES ${FLEUR_LIBRARIES}
+            LINK_LIBRARIES ${FLEUR_LIBRARIES} -lhdf5
             )
 endif()
 
 message("HDF5 Library found:${FLEUR_USE_HDF5}")
 
 if (DEFINED ENV{FLEUR_USE_HDF5})
-   if (ENV{FLEUR_USE_HDF5})
+   if ($ENV{FLEUR_USE_HDF5})
        if (NOT FLEUR_USE_HDF5)
            message(FATAL_ERROR "You asked for HDF5 but cmake couldn't find it. Please set HDF5_ROOT and or give additional compiler/linker flags")
        endif()
