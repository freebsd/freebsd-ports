--- UFconfig/UFconfig.mk	Wed Nov 29 20:18:52 2006
+++ UFconfig/UFconfig.mk	Thu Dec 28 09:14:51 2006
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
@@ -73,8 +73,8 @@
 # These settings will probably not work, since there is no fixed convention for
 # naming the BLAS and LAPACK library (*.a or *.so) files.  Assume the Goto
 # BLAS are available.
-BLAS = -lgoto -lgfortran -lgfortranbegin
-LAPACK = -llapack
+BLAS = %%BLAS%%
+LAPACK = %%LAPACK%%
 
 # The BLAS might not contain xerbla, an error-handling routine for LAPACK and
 # the BLAS.  Also, the standard xerbla requires the Fortran I/O library, and
@@ -102,8 +102,8 @@
 # The path is relative to where it is used, in CHOLMOD/Lib, CHOLMOD/MATLAB, etc.
 # You may wish to use an absolute path.  METIS is optional.  Compile
 # CHOLMOD with -DNPARTITION if you do not wish to use METIS.
-METIS_PATH = ../../metis-4.0
-METIS = ../../metis-4.0/libmetis.a
+METIS_PATH = %%LOCALBASE%%/include/metis
+METIS = %%LOCALBASE%%/lib/libmetis.a
 
 # If you use CHOLMOD_CONFIG = -DNPARTITION then you must use the following
 # options:
@@ -126,7 +126,7 @@
 # -DNRECIPROCAL	do not multiply by the reciprocal
 # -DNO_DIVIDE_BY_ZERO	do not divide by zero
 
-UMFPACK_CONFIG = 
+UMFPACK_CONFIG = -DGETRUSAGE
 
 #------------------------------------------------------------------------------
 # CHOLMOD configuration
@@ -176,12 +176,12 @@
 
 # alternatives:
 # CFLAGS = -g -fexceptions \
-   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
+#   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
 # CFLAGS = -O3 -fexceptions \
-   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
-CFLAGS = -O3 -fexceptions
+#   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
+CFLAGS = %%CFLAGS%%
 # CFLAGS = -O3
 
 # consider:
