--- make.inc.orig	2011-12-12 23:34:18.000000000 +0100
+++ make.inc	2014-08-26 23:26:34.000000000 +0200
@@ -21,14 +21,15 @@
 #
 #  The name of the libraries to be created/linked to
 #
-SuperLUroot	= $(HOME)/Codes/SuperLU/SuperLU_4.3
+SuperLUroot	= %%WRKSRC%%
 SUPERLULIB   	= $(SuperLUroot)/lib/libsuperlu_4.3.a
+SUPERLULIB_SHARED   = libsuperlu_4.3.so
 TMGLIB       	= libtmglib.a
 
 ## BLASLIB   	= $(SuperLUroot)/lib/libblas.a
 
 BLASDEF 	= -DUSE_VENDOR_BLAS
-BLASLIB 	= -L$(HOME)/lib/GotoBLAS -lgoto
+BLASLIB 	= %%BLAS%%
 
 ## ATLAS BLAS causes single-precision to fail
 #BLASLIB   	= -L/usr/lib/atlas -lblas
@@ -41,15 +42,14 @@
 #  The archiver and the flag(s) to use when building archive (library)
 #  If your system has no ranlib, set RANLIB = echo.
 #
-ARCH         = ar
+ARCMD        = ar
 ARCHFLAGS    = cr
 RANLIB       = ranlib
 
-CC           = gcc
-CFLAGS       = -DPRNTlevel=0 -O3
+CFLAGS       = -DPRNTlevel=0 %%CFLAGS%% -fpic
 NOOPTS       = 
-FORTRAN	     = g77
-FFLAGS       = -O2
+FORTRAN	     = %%FC%%
+FFLAGS       = %%FFLAGS%%
 LOADER       = $(CC)
 LOADOPTS     =
 
@@ -61,5 +61,5 @@
 #
 # The directory in which Matlab is installed
 #
-MATLAB	     = /usr/sww/matlab
+#MATLAB	     = /usr/sww/pkg/matlab
 
