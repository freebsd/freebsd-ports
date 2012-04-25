--- make.inc.orig	2006-01-02 00:52:00.000000000 +0100
+++ make.inc	2012-04-11 09:50:17.000000000 +0200
@@ -19,22 +19,25 @@
 #
 TMGLIB       = libtmglib.a
 SUPERLULIB   = libsuperlu_3.0.a
-BLASLIB      = ../libblas.a
+SUPERLULIB_SHARED   = libsuperlu_3.0.so
+BLASLIB      = -L/usr/local/lib -lblas
 
 #
 #  The archiver and the flag(s) to use when building archive (library)
 #  If your system has no ranlib, set RANLIB = echo.
 #
-ARCH         = ar
+ARCMD = ar
 ARCHFLAGS    = cr
 RANLIB       = ranlib
 
-CC           = cc
-CFLAGS       = -xO3 -xcg92
-FORTRAN	     = f77
-FFLAGS       = -O
-LOADER       = cc
-LOADOPTS     = -xO3
+#CC           ?= gcc46
+#CFLAGS       ?= -O3 -pipe -fno-strict-aliasing -march=native -Wl,-rpath=/usr/local/lib/gcc46
+#FORTRAN	     ?= gfortran46
+#FFLAGS       ?= -O -Wl,-rpath=/usr/local/lib/gcc46
+#LOADER       ?= gfortran46
+#LOADOPTS     = 
+
+CFLAGS       += -Wall -fpic
 
 #
 #  C preprocessor defs for compilation (-DNoChange, -DAdd_, or -DUpCase)
@@ -43,4 +46,4 @@
 #
 # The directory in which Matlab is installed
 #
-MATLAB	     = /usr/sww/pkg/matlab
+#MATLAB	     = /usr/sww/pkg/matlab
