--- make.inc.orig	2008-02-22 22:45:36 UTC
+++ make.inc
@@ -16,13 +16,13 @@
 #
 #  The machine (platform) identifier to append to the library names
 #
-PLAT = _sp
+PLAT = _PTHREAD
 
 #
 #  The name of the libraries to be created/linked to
 #
-TMGLIB       = libtmglib.a
-SUPERLULIB   = libsuperlu_mt$(PLAT).a
+TMGLIB       = libtmg.a
+SUPERLULIB   = libsuperlu_mt.a
 
 # 
 # If you don't have ESSL, you can use the following blaslib instead:
@@ -30,7 +30,7 @@ SUPERLULIB   = libsuperlu_mt$(PLAT).a
 # which may be slower than ESSL
 #
 BLASDEF	  = -DUSE_VENDOR_BLAS
-BLASLIB   = -lessl
+BLASLIB   = %%BLAS%%
 #BLASLIB   = ../lib/libblas$(PLAT).a
 MATHLIB	  = -lm 
 MPLIB	  = -lpthread
@@ -38,7 +38,7 @@ MPLIB	  = -lpthread
 #  The archiver and the flag(s) to use when building archive (library)
 #  If your system has no ranlib, set RANLIB = echo.
 #
-ARCH         = ar
+ARCMD        = ar
 ARCHFLAGS    = cr
 RANLIB       = ranlib
 
@@ -46,16 +46,17 @@ RANLIB       = ranlib
 PREDEFS      	= -D_PTHREAD
 #
 
-CC           = xlc_r
-CFLAGS       = -qarch=pwr5 -qalias=allptrs $(PREDEFS) -DPRNTlevel=0 -O3
-FORTRAN	     = xlf
-FFLAGS       = -O3 -qarch=pwr5
-LOADER       = xlc_r
-LOADOPTS     = -bmaxdata:0x80000000
+CC           = %%CC%%
+CFLAGS       = $(PREDEFS) %%CPPFLAGS%% %%CFLAGS%%
+FORTRAN      = %%FC%%
+FFLAGS       = %%FFLAGS%%
+LOADER       = %%CC%%
+LOADOPTS     = %%LDFLAGS%%
+NOOPTS       = %%FPIC%%
 #
 #  C preprocessor defs for compilation for the Fortran interface
 #  (-DNoChange, -DAdd_, -DAdd__, or -DUpCase)
 #
-CDEFS        = -DNoChange
+CDEFS        = -DAdd_
 
 
