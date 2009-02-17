--- UFconfig/UFconfig.mk~	2009-02-16 14:40:18.000000000 +0900
+++ UFconfig/UFconfig.mk	2009-02-16 14:44:33.000000000 +0900
@@ -33,11 +33,11 @@
 # C compiler and compiler flags:  These will normally not give you optimal
 # performance.  You should select the optimization parameters that are best
 # for your system.  On Linux, use "CFLAGS = -O3 -fexceptions" for example.
-CC = cc
-# CFLAGS = -O   (for example; see below for details)
+CC = %%CC%%
+CFLAGS = %%CFLAGS%%
 
 # C++ compiler (also uses CFLAGS)
-CPLUSPLUS = g++
+CPLUSPLUS = %%CXX%%
 
 # ranlib, and ar, for generating libraries
 RANLIB = ranlib
@@ -48,8 +48,8 @@
 MV = mv -f
 
 # Fortran compiler (not normally required)
-F77 = f77
-F77FLAGS = -O
+F77 = %%F77%%
+F77FLAGS = %%FFLAGS%%
 F77LIB =
 
 # C and Fortran libraries
@@ -89,8 +89,8 @@
 # BLAS = -lgoto -lgfortran -lgfortranbegin -lg2c
 
 # This is probably slow ... it might connect to the Standard Reference BLAS:
-BLAS = -lblas -lgfortran -lgfortranbegin -lg2c
-LAPACK = -llapack
+BLAS = %%BLAS%% %%FORTRANRUNTIME%%
+LAPACK = %%LAPACK%%
 
 # Using non-optimized versions:
 # BLAS = -lblas_plain -lgfortran -lgfortranbegin -lg2c
@@ -122,8 +122,8 @@
 # The path is relative to where it is used, in CHOLMOD/Lib, CHOLMOD/MATLAB, etc.
 # You may wish to use an absolute path.  METIS is optional.  Compile
 # CHOLMOD with -DNPARTITION if you do not wish to use METIS.
-METIS_PATH = ../../metis-4.0
-METIS = ../../metis-4.0/libmetis.a
+METIS_PATH = %%METIS_PATH%%
+METIS = %%METIS%%
 
 # If you use CHOLMOD_CONFIG = -DNPARTITION then you must use the following
 # options:
@@ -184,7 +184,7 @@
 # -DNSUNPERF	    for Solaris only.  If defined, do not use the Sun
 #			Performance Library
 
-CHOLMOD_CONFIG =
+CHOLMOD_CONFIG = %%CHOLMOD_CONFIG%%
 
 #------------------------------------------------------------------------------
 # SuiteSparseQR configuration:
@@ -198,7 +198,7 @@
 # -DHAVE_TBB        enable the use of Intel's Threading Building Blocks (TBB)
 
 # default, without timing, without TBB:
-SPQR_CONFIG =
+SPQR_CONFIG = %%CHOLMOD_CONFIG%%
 # with timing and TBB:
 # SPQR_CONFIG = -DTIMING -DHAVE_TBB
 # with timing
@@ -220,15 +220,15 @@
 
 # Using default compilers:
 # CC = gcc
-CFLAGS = -O3 -fexceptions
+# CFLAGS = -O3 -fexceptions
 
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
 # CFLAGS = -O3 -g -fexceptions

