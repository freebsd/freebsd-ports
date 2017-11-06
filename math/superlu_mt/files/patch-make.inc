--- make.inc.orig	2015-04-30 00:46:42 UTC
+++ make.inc
@@ -22,7 +22,7 @@ PLAT = _PTHREAD
 TMGLIB       	= libtmglib$(PLAT).a
 SUPERLULIB   	= libsuperlu_mt$(PLAT).a
 BLASDEF	        = -DUSE_VENDOR_BLAS
-BLASLIB		= -L/usr/lib -lf77blas -latlas
+BLASLIB		= %%BLAS%%
 #BLASLIB = ../lib/libblas$(PLAT).a
 MATHLIB		= -lm 
 MPLIB		= -lpthread
@@ -31,7 +31,7 @@ MPLIB		= -lpthread
 #  The archiver and the flag(s) to use when building archive (library)
 #  If your system has no ranlib, set RANLIB = echo.
 #
-ARCH          	= ar
+ARCMD          	= ar
 ARCHFLAGS     	= cr
 RANLIB       	= ranlib
 
@@ -40,8 +40,8 @@ RANLIB       	= ranlib
 # Definitions used by CPP:
 PREDEFS      	= -D__PTHREAD  ## -DDEBUGlevel=0 -DPRNTlevel=0
 #
-CC           	= gcc
-CFLAGS       	= $(PREDEFS) -g #-O3
+CC           	= %%CC%%
+CFLAGS       	= $(PREDEFS) %%CFLAGS%%
 # Uncomment the following to use 64-bit integer
 CFLAGS          += -D_LONGINT
 
@@ -49,19 +49,19 @@ CFLAGS          += -D_LONGINT
 # There are a few files that should NOT be optimized, which appear in the
 # end of SRC/Makefile, taking the flag $(NOOPTS)
 # NOOPTS should be defined to explicitly turn off any optimization.
-NOOPTS	     	= -O0
+NOOPTS	     	= -O0 %%FPIC%%
 
-BLASOPTS	=
+BLASOPTS	= 
 
 ############################################################################
 
-FORTRAN		= gfortran
-FFLAGS		= -O -fdefault-integer-8
+FORTRAN		= %%FC%%
+FFLAGS		= %%FFLAGS%% -fdefault-integer-8
 
 ############################################################################
 
-LOADER       	= gcc
-LOADOPTS     	= -O #-pthread
+LOADER       	= %%CC%%
+LOADOPTS     	= -O %%LDFLAGS%%
 
 ############################################################################
 #
