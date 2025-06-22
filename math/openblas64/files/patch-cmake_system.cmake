--- cmake/system.cmake.orig	2025-06-19 09:45:39 UTC
+++ cmake/system.cmake
@@ -380,8 +380,9 @@ if (USE_OPENMP)
     # Avoid mixed OpenMP linkage
     get_target_property(OMP_C_LIB OpenMP::OpenMP_C INTERFACE_LINK_LIBRARIES)
     get_target_property(OMP_Fortran_LIB OpenMP::OpenMP_Fortran INTERFACE_LINK_LIBRARIES)
+# Disable this error on FreeBSD (dangerous by OK for the moment)
     if (NOT OMP_C_LIB STREQUAL OMP_Fortran_LIB)
-      message(FATAL_ERROR "Multiple OpenMP runtime libraries detected. Mixed OpenMP runtime linkage is dangerous. You may pass -DOpenMP_LANG_LIB_NAMES and -DOpenMP_omp_LIBRARY to manually choose the OpenMP library.")
+      message(STATUS "Multiple OpenMP runtime libraries detected. Mixed OpenMP runtime linkage is dangerous. You may pass -DOpenMP_LANG_LIB_NAMES and -DOpenMP_omp_LIBRARY to manually choose the OpenMP library.")
     endif()
   endif ()
 endif ()
