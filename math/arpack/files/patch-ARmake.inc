--- ARmake.inc.orig	Fri Apr 26 14:12:57 1996
+++ ARmake.inc	Fri Jul 11 16:41:11 2003
@@ -25,14 +25,14 @@
 # | other than your home directory.      |
 # %--------------------------------------%
 #
-home = $(HOME)/ARPACK
+home = %%WRKDIR%%/ARPACK
 #
 #  %--------------------------------------%
 #  | The platform identifier to suffix to |
 #  | the end of library names             |
 #  %--------------------------------------%
 #
-PLAT = SUN4
+PLAT = FBSD
 #
 #  %------------------------------------------------------%
 #  | The directories to find the various pieces of ARPACK |
@@ -43,7 +43,7 @@
 UTILdir      = $(home)/UTIL
 SRCdir       = $(home)/SRC
 #
-DIRS        = $(BLASdir) $(LAPACKdir) $(UTILdir) $(SRCdir)
+DIRS        = $(LAPACKdir) $(UTILdir) $(SRCdir)
 #
 # %-------------------------------------------------------------------%
 # | Comment out the previous line and uncomment the following         |
@@ -57,9 +57,9 @@
 # | The name of the libraries to be created/linked to |
 # %---------------------------------------------------%
 #
-ARPACKLIB  = $(home)/libarpack_$(PLAT).a
-LAPACKLIB = 
-BLASLIB = 
+ARPACKLIB  = $(home)/libarpack.a
+LAPACKLIB = $(home)/liblapack.a
+BLASLIB = %%BLAS_LIBS%%
 #
 ALIBS =  $(ARPACKLIB) $(LAPACKLIB) $(BLASLIB) 
 #
@@ -101,8 +101,8 @@
 # | for your system.                        |
 # %-----------------------------------------%
 #
-FC      = f77
-FFLAGS	= -O -cg89
+FC      = %FC%
+FFLAGS	= %FFLAGS%
 
 LDFLAGS = 
 CD      = cd
@@ -112,7 +112,7 @@
 LN      = ln
 LNFLAGS = -s
 
-MAKE    = /bin/make
+MAKE    ?= /usr/bin/make
 
 RM      = rm
 RMFLAGS = -f
