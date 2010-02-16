--- make.inc.orig	2006-01-01 18:52:00.000000000 -0500
+++ make.inc	2008-06-19 22:08:49.000000000 -0500
@@ -19,7 +19,7 @@
 #
 TMGLIB       = libtmglib.a
 SUPERLULIB   = libsuperlu_3.0.a
-BLASLIB      = ../libblas.a
+BLASLIB      = %%BLAS%%
 
 #
 #  The archiver and the flag(s) to use when building archive (library)
@@ -29,12 +29,12 @@
 ARCHFLAGS    = cr
 RANLIB       = ranlib
 
-CC           = cc
-CFLAGS       = -xO3 -xcg92
-FORTRAN	     = f77
-FFLAGS       = -O
-LOADER       = cc
-LOADOPTS     = -xO3
+CC           = %%CC%%
+CFLAGS       = %%CFLAGS%%
+FORTRAN	     = %%FC%%
+FFLAGS       = %%FFLAGS%%
+LOADER       = %%FC%%
+LOADOPTS     = 
 
 #
 #  C preprocessor defs for compilation (-DNoChange, -DAdd_, or -DUpCase)
