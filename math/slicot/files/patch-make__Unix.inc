--- make_Unix.inc.orig	2024-02-05 12:03:37 UTC
+++ make_Unix.inc
@@ -14,7 +14,7 @@ FORTRAN = gfortran
 #  the compiler options desired when NO OPTIMIZATION is selected.
 #
 FORTRAN = gfortran
-OPTS = -O2 -fPIC -fdefault-integer-8
+#OPTS = -O2 -fPIC -fdefault-integer-8
 OPTS_NOOPT = -O0
 
 #  Define LDFLAGS to the desired linker options for your machine.
@@ -30,13 +30,11 @@ ARCHFLAGS = cr
 # ARCHFLAGS= r
 # RANLIB   = ranlib
 
-LOADOPTS = $(SLICOTLIB) $(LPKAUXLIB) $(LAPACKLIB) $(BLASLIB)
+#LOADOPTS = $(SLICOTLIB) $(LPKAUXLIB) $(LAPACKLIB) $(BLASLIB)
 #
 #  The location of the libraries to which you will link.  (The
 #  machine-specific, optimized BLAS library should be used whenever
 #  possible.)
 #
-BLASLIB      = ../libs/blas.a
-LAPACKLIB    = ../libs/lapack.a
 LPKAUXLIB    = ../lpkaux.a
 SLICOTLIB    = ../slicot.a
