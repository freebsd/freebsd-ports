--- make.inc.orig	Thu Jan 22 09:45:17 2004
+++ make.inc	Thu Apr  1 20:34:07 2004
@@ -16,14 +16,15 @@
 #
 #  The machine (platform) identifier to append to the library names
 #
-PLAT = _solaris
+#PLAT =
 
 #
 #  The name of the libraries to be created/linked to
 #
-TMGLIB       = tmglib$(PLAT).a
-SUPERLULIB   = superlu$(PLAT).a
-BLASLIB      = ../blas$(PLAT).a
+TMGLIB       = libtmg.a
+SUPERLULIB   = libsuperlu.a
+BLASDEF	     = -DUSE_VENDOR_BLAS
+BLASLIB      = %%BLAS_LIBS%%
 
 #
 #  The archiver and the flag(s) to use when building archive (library)
@@ -33,12 +34,12 @@
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
+LOADER       = %%CC%%
+LOADOPTS     = 
 
 #
 #  C preprocessor defs for compilation (-DNoChange, -DAdd_, or -DUpCase)
