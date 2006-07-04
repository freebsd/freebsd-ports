--- UFconfig/UFconfig.mk	Tue May  2 22:34:57 2006
+++ UFconfig/UFconfig.mk	Tue Jul  4 11:44:40 2006
@@ -31,8 +31,8 @@
 # C compiler and compiler flags:  These will normally not give you optimal
 # performance.  You should select the optimization parameters that are best
 # for your system.  On Linux, use "CFLAGS = -O3 -fexceptions" for example.
-CC = cc
-CFLAGS = -O
+CC = %%CC%%
+CFLAGS = %%CFLAGS%%
 
 # ranlib, and ar, for generating libraries
 RANLIB = ranlib
@@ -43,8 +43,8 @@
 MV = mv -f
 
 # Fortran compiler (not normally required)
-F77 = f77
-F77FLAGS = -O
+F77 = %%F77%%
+F77FLAGS = %%FFLAGS%%
 F77LIB =
 
 # C and Fortran libraries
@@ -76,8 +76,8 @@
 
 # These settings will probably not work, since there is no fixed convention for
 # naming the BLAS and LAPACK library (*.a or *.so) files.
-BLAS = -lblas -lg2c
-LAPACK = -llapack
+BLAS = %%BLAS%%
+LAPACK = %%LAPACK%%
 
 # The BLAS might not contain xerbla, an error-handling routine for LAPACK and
 # the BLAS.  Also, the standard xerbla requires the Fortran I/O library, and
@@ -101,8 +101,8 @@
 # The path is relative to where it is used, in CHOLMOD/Lib, CHOLMOD/MATLAB, etc.
 # You may wish to use an absolute path.  METIS is optional.  Compile
 # CHOLMOD with -DNPARTITION if you do not wish to use METIS.
-METIS_PATH = ../../metis-4.0
-METIS = ../../metis-4.0/libmetis.a
+METIS_PATH = /usr/local/include/metis
+METIS = /usr/local/lib/libmetis.a
 
 # If you use CHOLMOD_CONFIG = -DNPARTITION then use the following options:
 # METIS_PATH =
