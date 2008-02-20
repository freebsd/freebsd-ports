--- UFconfig/UFconfig.mk.orig	2007-10-24 22:55:44.000000000 +0900
+++ UFconfig/UFconfig.mk	2008-02-03 12:04:00.000000000 +0900
@@ -32,8 +32,8 @@
 # C compiler and compiler flags:  These will normally not give you optimal
 # performance.  You should select the optimization parameters that are best
 # for your system.  On Linux, use "CFLAGS = -O3 -fexceptions" for example.
-CC = cc
-CFLAGS = -O
+CC = %%CC%%
+CFLAGS = %%CFLAGS%%
 
 # ranlib, and ar, for generating libraries
 RANLIB = ranlib
@@ -44,8 +44,9 @@
 MV = mv -f
 
 # Fortran compiler (not normally required)
-F77 = f77
-F77FLAGS = -O
+F77 = %%F77%%
+FC  = %%FC%%
+F77FLAGS = %%FFLAGS%%
 F77LIB =
 
 # C and Fortran libraries
@@ -85,8 +86,8 @@
 # BLAS = -lgoto -lgfortran -lgfortranbegin
 
 # This is probably slow ... it might connect to the Standard Reference BLAS:
-BLAS = -lblas -lgfortran -lgfortranbegin
-LAPACK = -llapack
+BLAS = %%BLAS%%
+LAPACK = %%LAPACK%%
 
 # The BLAS might not contain xerbla, an error-handling routine for LAPACK and
 # the BLAS.  Also, the standard xerbla requires the Fortran I/O library, and
@@ -114,8 +115,8 @@
 # The path is relative to where it is used, in CHOLMOD/Lib, CHOLMOD/MATLAB, etc.
 # You may wish to use an absolute path.  METIS is optional.  Compile
 # CHOLMOD with -DNPARTITION if you do not wish to use METIS.
-METIS_PATH = ../../metis-4.0
-METIS = ../../metis-4.0/libmetis.a
+METIS_PATH = %%METIS_PATH%%
+METIS = %%METIS%%
 
 # If you use CHOLMOD_CONFIG = -DNPARTITION then you must use the following
 # options:
@@ -138,7 +139,7 @@
 # -DNRECIPROCAL	do not multiply by the reciprocal
 # -DNO_DIVIDE_BY_ZERO	do not divide by zero
 
-UMFPACK_CONFIG = 
+UMFPACK_CONFIG = -DGETRUSAGE
 
 #------------------------------------------------------------------------------
 # CHOLMOD configuration
@@ -177,7 +177,7 @@
 # -DNSUNPERF	    for Solaris only.  If defined, do not use the Sun
 #			Performance Library
 
-CHOLMOD_CONFIG =
+CHOLMOD_CONFIG = %%CHOLMOD_CONFIG%%
 
 #------------------------------------------------------------------------------
 # Linux
@@ -184,15 +185,15 @@
 
 # Using default compilers:
 # CC = gcc
-CFLAGS = -O3
+# CFLAGS = -O3
 
 # alternatives:
 # CFLAGS = -g -fexceptions \
-   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
+#   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
 # CFLAGS = -O3 -fexceptions \
-   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
+#   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
 # CFLAGS = -O3 -fexceptions -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE
 # CFLAGS = -O3
