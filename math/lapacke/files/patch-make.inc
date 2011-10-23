--- make.inc.orig	2010-10-01 17:17:25.000000000 +0900
+++ make.inc	2010-12-06 20:00:25.000000000 +0900
@@ -47,20 +47,20 @@
 #                  LDFLAGS = -nofor-main
 # - gfortran, set: LINKER = gfortran
 #
-CC = icc
-CFLAGS = -O3
+CC = %%CC%%
+CFLAGS = %%CFLAGS%%
 LINKER = $(CC)
-LDFLAGS =
+LDFLAGS = %%LDFLAGS%%
 #
 # The name of the libraries to be created/linked to
 # Ensure that the libraries have the same data model (LP64/ILP64).
 #
-LAPACKE = lapacke.a
-LIBS = ../../../lapack-3.2.1/lapack.a ../../../lapack-3.2.1/blas.a -lm
+LAPACKE = ./lib/liblapacke.a
+LIBS = %%LAPACK%% %%BLAS%%
 #
 #  The archiver and the flag(s) to use when building archive (library)
 #  If your system has no ranlib, set RANLIB = echo.
 #
-ARCH         = ar
-ARCHFLAGS    = cr
-RANLIB       = ranlib
+ARCH_        = %%AR%%
+ARCH_FLAGS   = cr
+RANLIB       = %%RANLIB%%
