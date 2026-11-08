-- remove native option

--- cmake/compilerflags.cmake.orig	2026-11-08 23:37:02 UTC
+++ cmake/compilerflags.cmake
@@ -64,7 +64,6 @@ elseif (CMAKE_Fortran_COMPILER_ID MATCHES "GNU")
    endif()
    #set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -ffree-line-length-none -Wno-missing-include-dirs -DCPP_IRAPPROX")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -ffree-line-length-none -Wno-missing-include-dirs -fno-sign-zero -fPIC")
-   set(CMAKE_Fortran_FLAGS_RELEASE "${CMAKE_Fortran_FLAGS_RELEASE} -Ofast  -mtune=native -g")
    set(CMAKE_Fortran_FLAGS_DEBUG "${CMAKE_Fortran_FLAGS_DEBUG} -fdump-core -Wall -Wextra -Wno-array-temporaries  -fbacktrace -fcheck=all  -finit-real=nan -O0 -g -DCPP_DEBUG")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
  elseif (CMAKE_Fortran_COMPILER_ID MATCHES "Cray")
