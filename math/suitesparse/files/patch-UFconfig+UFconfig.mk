--- UFconfig/UFconfig.mk.orig	2011-05-11 05:47:15.000000000 +0900
+++ UFconfig/UFconfig.mk	2011-06-22 16:35:36.000000000 +0900
@@ -33,11 +33,11 @@
 # C compiler and compiler flags:  These will normally not give you optimal
 # performance.  You should select the optimization parameters that are best
 # for your system.  On Linux, use "CFLAGS = -O3 -fexceptions" for example.
-CC = cc
-CFLAGS = -O3 -fexceptions
+CC = %%CC%%
+CFLAGS = %%CFLAGS%%
 
 # C++ compiler (also uses CFLAGS)
-CPLUSPLUS = g++
+CPLUSPLUS = %%CXX%%
 
 # ranlib, and ar, for generating libraries
 RANLIB = ranlib
@@ -49,8 +49,8 @@
 MV = mv -f
 
 # Fortran compiler (not normally required)
-F77 = f77
-F77FLAGS = -O
+F77 = %%F77%%
+F77FLAGS = %%FFLAGS%%
 F77LIB =
 
 # C and Fortran libraries
@@ -91,8 +91,8 @@
 # naming the BLAS and LAPACK library (*.a or *.so) files.
 
 # This is probably slow ... it might connect to the Standard Reference BLAS:
-BLAS = -lblas -lgfortran
-LAPACK = -llapack
+BLAS = %%BLAS%% %%FORTRANRUNTIME%%
+LAPACK = %%LAPACK%%
 
 # NOTE: this next option for the "Goto BLAS" has nothing to do with a "goto"
 # statement.  Rather, the Goto BLAS is written by Dr. Kazushige Goto.
@@ -132,8 +132,8 @@
 # The path is relative to where it is used, in CHOLMOD/Lib, CHOLMOD/MATLAB, etc.
 # You may wish to use an absolute path.  METIS is optional.  Compile
 # CHOLMOD with -DNPARTITION if you do not wish to use METIS.
-METIS_PATH = ../../metis-4.0
-METIS = ../../metis-4.0/libmetis.a
+METIS_PATH = %%METIS_PATH%%
+METIS = %%METIS%%
 
 # If you use CHOLMOD_CONFIG = -DNPARTITION then you must use the following
 # options:
@@ -194,7 +194,7 @@
 # -DNSUNPERF	    for Solaris only.  If defined, do not use the Sun
 #			Performance Library
 
-CHOLMOD_CONFIG =
+CHOLMOD_CONFIG = %%CHOLMOD_CONFIG%%
 
 #------------------------------------------------------------------------------
 # SuiteSparseQR configuration:
@@ -208,7 +208,7 @@
 # -DHAVE_TBB        enable the use of Intel's Threading Building Blocks (TBB)
 
 # default, without timing, without TBB:
-SPQR_CONFIG =
+SPQR_CONFIG = %%CHOLMOD_CONFIG%%
 # with timing and TBB:
 # SPQR_CONFIG = -DTIMING -DHAVE_TBB
 # with timing
@@ -237,18 +237,18 @@
 
 # alternatives:
 # CFLAGS = -g -fexceptions \
-   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi \
-        -funit-at-a-time
+#   	-Wall -W -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi \
+#       -funit-at-a-time
 # CFLAGS = -O3 -fexceptions \
-   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
-    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
+#   	-Wall -W -Werror -Wshadow -Wmissing-prototypes -Wstrict-prototypes \
+#    	-Wredundant-decls -Wnested-externs -Wdisabled-optimization -ansi
 # CFLAGS = -O3 -fexceptions -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE
 # CFLAGS = -O3
 # CFLAGS = -O3 -g -fexceptions
 # CFLAGS = -g -fexceptions \
-   	-Wall -W -Wshadow \
-    	-Wredundant-decls -Wdisabled-optimization -ansi
+#   	-Wall -W -Wshadow \
+#    	-Wredundant-decls -Wdisabled-optimization -ansi
 
 # consider:
 # -fforce-addr -fmove-all-movables -freduce-all-givs -ftsp-ordering
