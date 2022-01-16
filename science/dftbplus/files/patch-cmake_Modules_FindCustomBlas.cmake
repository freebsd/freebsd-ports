- workaround for https://gitlab.kitware.com/cmake/cmake/-/issues/23088

--- cmake/Modules/FindCustomBlas.cmake.orig	2022-01-16 08:14:03 UTC
+++ cmake/Modules/FindCustomBlas.cmake
@@ -87,6 +87,10 @@ else()
       # No user customized BLAS library, try built-in finder
       if(NOT BLAS_FOUND)
         find_package(BLAS)
+        if (BLAS_FOUND AND "${BLAS_LIBRARY}" STREQUAL "")
+          message(STATUS "(!!!) after find_package(BLAS): BLAS_FOUND=${BLAS_FOUND} BLAS_LIBRARIES=${BLAS_LIBRARIES}")
+          set(BLAS_LIBRARIES blas)
+        endif()
       endif()
       set(BLAS_LIBRARY "${BLAS_LIBRARIES}" CACHE STRING "BLAS library to link" FORCE)
       set(BLAS_LINKER_FLAG "${BLAS_LINKER_FLAGS}" CACHE STRING
