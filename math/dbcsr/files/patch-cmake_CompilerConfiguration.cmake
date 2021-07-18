--- cmake/CompilerConfiguration.cmake.orig	2021-05-24 06:47:19 UTC
+++ cmake/CompilerConfiguration.cmake
@@ -1,5 +1,5 @@
 if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
-  set(CMAKE_Fortran_FLAGS          "-ffree-form -std=f2008ts -fimplicit-none -Werror=aliasing -Werror=ampersand -Werror=c-binding-type -Werror=intrinsic-shadow -Werror=intrinsics-std -Werror=line-truncation -Werror=tabs -Werror=target-lifetime -Werror=underflow -Werror=unused-but-set-parameter -Werror=unused-but-set-variable -Werror=unused-variable -Werror=unused-dummy-argument -Werror=conversion -Werror=zerotrip -Werror=uninitialized -Wno-maybe-uninitialized -Werror=unused-parameter")
+  set(CMAKE_Fortran_FLAGS          "${CMAKE_Fortran_FLAGS} -ffree-form -std=f2008ts -fimplicit-none -Werror=aliasing -Werror=ampersand -Werror=c-binding-type -Werror=intrinsic-shadow -Werror=intrinsics-std -Werror=line-truncation -Werror=tabs -Werror=target-lifetime -Werror=underflow -Werror=unused-but-set-parameter -Werror=unused-but-set-variable -Werror=unused-variable -Werror=unused-dummy-argument -Werror=conversion -Werror=zerotrip -Werror=uninitialized -Wno-maybe-uninitialized -Werror=unused-parameter")
   if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10)
     set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -Werror=argument-mismatch")  # gcc 10+ has this automatically
   endif ()
