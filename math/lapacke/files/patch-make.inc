--- make.inc.orig	2011-11-10 07:56:15.000000000 +0900
+++ make.inc	2011-12-03 20:22:18.000000000 +0900
@@ -47,20 +47,19 @@
 #                  LDFLAGS = -nofor-main
 # - gfortran, set: LINKER = gfortran
 #
-CC = gcc
-CFLAGS =
-LINKER = gfortran
-LDFLAGS =
+CC = %%CC%%
+CFLAGS = %%CFLAGS%%
+LINKER = $(CC)
+LDFLAGS = %%LDFLAGS%%
 #
 # The name of the libraries to be created/linked to
 # Ensure that the libraries have the same data model (LP64/ILP64).
 #
-LAPACKE = lapacke.a
-LIBS =  /Users/julie/Documents/Boulot/lapack-dev/lapack/trunk/lapack_LINUX.a \
-        /Users/julie/Documents/Boulot/lapack-dev/lapack/trunk/blas_LINUX.a  -lm
+LAPACKE = ./lib%%LAPACKE_LIBNAME%%.a
+LIBS = %%LAPACK%% %%BLAS%%
 #  The archiver and the flag(s) to use when building archive (library)
 #  If your system has no ranlib, set RANLIB = echo.
 #
-ARCH         = ar
+ARCH_        = %%AR%%
 ARCHFLAGS    = cr
-RANLIB       = ranlib
+RANLIB       = %%RANLIB%%
