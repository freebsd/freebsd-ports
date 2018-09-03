--- cmake/tests/test_ELPA.cmake.orig	2018-07-03 14:37:33 UTC
+++ cmake/tests/test_ELPA.cmake
@@ -1,6 +1,6 @@
 #First check if we can compile with ELPA
 try_compile(FLEUR_USE_ELPA ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_ELPA.f90
-LINK_LIBRARIES ${FLEUR_LIBRARIES})
+LINK_LIBRARIES ${FLEUR_LIBRARIES} -lelpa)
 
 if (NOT FLEUR_USE_ELPA)
    set(STORE_FLAGS "${CMAKE_Fortran_FLAGS}")
@@ -63,3 +63,7 @@ LINK_LIBRARIES ${FLEUR_LIBRARIES})
        set(FLEUR_MPI_DEFINITIONS ${FLEUR_MPI_DEFINITIONS} "CPP_ELPA" "CPP_ELPA2" "CPP_ELPA_201705003")
    endif()
 endif() 
+
+if (FLEUR_USE_ELPA AND NOT ${FREEBSD_USE_ELPA})
+   set(FLEUR_USE_ELPA OFF)
+endif()
