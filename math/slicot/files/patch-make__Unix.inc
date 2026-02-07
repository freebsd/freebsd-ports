--- make_Unix.inc.orig	2025-11-04 14:46:11 UTC
+++ make_Unix.inc
@@ -14,7 +14,7 @@ FORTRAN = gfortran
 #  the compiler options desired when NO OPTIMIZATION is selected.
 #
 FORTRAN = gfortran
-OPTS = -O2 -fPIC -g
+#OPTS = -O2 -fPIC -g
 OPTS_NOOPT = -O0 -g
 
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
-BLASLIB      = -lopenblas
-LAPACKLIB    = -lopenblas
 LPKAUXLIB    = ../lpkaux.a
 SLICOTLIB    = ../slicot.a
