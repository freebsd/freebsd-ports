--- make.inc	Fri Jan 18 05:53:51 2008
+++ make.inc	Thu Jul  3 12:47:55 2008
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
@@ -30,10 +30,10 @@
 # which may be slower than ESSL
 #
 BLASDEF	  = -DUSE_VENDOR_BLAS
-BLASLIB   = -lessl
+BLASLIB   = %%BLAS_LIBS%%
 #BLASLIB   = ../lib/libblas$(PLAT).a
 MATHLIB	  = -lm 
-MPLIB	  = -lpthread
+MPLIB	  = %%PTHREAD_LIBS%%
 
 #  The archiver and the flag(s) to use when building archive (library)
 #  If your system has no ranlib, set RANLIB = echo.
@@ -46,16 +46,17 @@
 PREDEFS      	= -D_PTHREAD
 #
 
-CC           = xlc_r
-CFLAGS       = -qarch=pwr5 -qalias=allptrs $(PREDEFS) -DPRNTlevel=0 -O3
-FORTRAN	     = xlf
-FFLAGS       = -O3 -qarch=pwr5
-LOADER       = xlc_r
-LOADOPTS     = -bmaxdata:0x80000000
+CC           = %%CC%%
+CFLAGS       = $(PREDEFS) %%CFLAGS%% %%PTHREAD_CFLAGS%%
+FORTRAN	     = %%FC%%
+FFLAGS       = %%FFLAGS%%
+LOADER       = %%FC%%
+LOADOPTS     = -O
+NOOPTS       = %%FPIC%%
 #
 #  C preprocessor defs for compilation for the Fortran interface
 #  (-DNoChange, -DAdd_, -DAdd__, or -DUpCase)
 #
-CDEFS        = -DNoChange
+CDEFS        = -DAdd_
 
 
