--- cmake/tests/test_SCALAPACK.cmake.orig	2018-07-03 14:37:33 UTC
+++ cmake/tests/test_SCALAPACK.cmake
@@ -1,9 +1,13 @@
 #First check if we can compile with LAPACK
 try_compile(FLEUR_USE_SCALAPACK ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/cmake/tests/test_SCALAPACK.f90
-LINK_LIBRARIES ${FLEUR_LIBRARIES}
+LINK_LIBRARIES ${FLEUR_LIBRARIES} -lscalapack
             )
 
 message("SCALAPACK Library found:${FLEUR_USE_SCALAPACK}")
 if (FLEUR_USE_SCALAPACK)
    set(FLEUR_MPI_DEFINITIONS ${FLEUR_MPI_DEFINITIONS} "CPP_SCALAPACK")
-endif()
\ No newline at end of file
+endif()
+
+if (FLEUR_USE_SCALAPACK AND NOT ${FREEBSD_USE_SCALAPACK})
+   set(FLEUR_USE_SCALAPACK OFF)
+endif()
