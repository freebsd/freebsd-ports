--- make.inc.orig	Thu Sep  2 15:47:13 1999
+++ make.inc	Tue May 27 19:32:12 2003
@@ -14,14 +14,15 @@
 #
 #  The machine (platform) identifier to append to the library names
 #
-PLAT = _SOLARIS
+PLAT = _PTHREAD
 
 # Common Libraries
-TMGLIB       	= tmglib$(PLAT).a
-SUPERLULIB   	= superlu_mt$(PLAT).a
-BLASLIB     	= ../blas$(PLAT).a
+TMGLIB       	= libtmg.a
+SUPERLULIB   	= libsuperlu_mt.a
+BLASDEF		= -DUSE_VENDOR_BLAS
+BLASLIB     	= %%BLAS_LIBS%%
 MATHLIB	     	= -lm 
-MPLIB		= -lthread
+MPLIB		= %%PTHREAD_LIBS%%
 
 #
 #  The archiver and the flag(s) to use when building archive (library)
@@ -32,18 +33,18 @@
 RANLIB       	= ranlib
 
 # for Solaris 2.x
-CC	     	= cc
+CC	     	?= cc
 #
 # Definitions used by CPP:
 PREDEFS      	= -D$(PLAT)
 #
-CFLAGS       	= $(PREDEFS) -xO3 -xcg92 $(DBG)
+CFLAGS       	+= $(PREDEFS) %%PTHREAD_CFLAGS%%
 NOOPTS	     	=
 BLASOPTS	=
 LOADER       	= cc
 LOADOPTS     	= -O
-FORTRAN		= f77
-FFLAGS		= -O
+FORTRAN		?= f77
+FFLAGS		?= -O
 
 #
 #  C preprocessor defs for compilation (-DNoChange, -DAdd_, or -DUpCase)
