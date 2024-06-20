- otherwise USE_LAPACK=1 fails to find lapack

--- cmake/Modules/FindBLAS.cmake.orig	2024-06-20 08:11:50 UTC
+++ cmake/Modules/FindBLAS.cmake
@@ -20,7 +20,7 @@ SET(BLAS_F2C)
 SET(BLAS_INFO)
 SET(BLAS_F2C)
 
-SET(WITH_BLAS "" CACHE STRING "Blas type [accelerate/acml/atlas/blis/generic/goto/mkl/open/veclib]")
+SET(WITH_BLAS "open" CACHE STRING "Blas type [accelerate/acml/atlas/blis/generic/goto/mkl/open/veclib]")
 
 # Old FindBlas
 INCLUDE(CheckCSourceRuns)
