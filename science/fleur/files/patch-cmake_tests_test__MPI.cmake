--- cmake/tests/test_MPI.cmake.orig	2018-07-03 14:37:33 UTC
+++ cmake/tests/test_MPI.cmake
@@ -1,12 +1,12 @@
 #Check if we can compile with MPI
 try_compile(FLEUR_USE_MPI ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_MPI.f90
-LINK_LIBRARIES ${FLEUR_LIBRARIES}
+LINK_LIBRARIES ${FLEUR_LIBRARIES} -lmpich -lmpifort
             )
 
 message("MPI Library found:${FLEUR_USE_MPI}")
 
 if (DEFINED ENV{FLEUR_USE_MPI})
-   if (ENV{FLEUR_USE_MPI})
+   if ($ENV{FLEUR_USE_MPI})
        if (NOT FLEUR_USE_MPI)
            message(FATAL_ERROR "You asked for MPI but cmake couldn't find it. Please check your Fortran compiler settings")
        endif()
