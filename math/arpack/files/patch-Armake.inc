--- ARmake.inc.orig	Sat Apr 27 04:12:57 1996
+++ ARmake.inc	Mon May  5 20:12:25 2003
@@ -25,14 +25,14 @@
 # | other than your home directory.      |
 # %--------------------------------------%
 #
-home = $(HOME)/ARPACK
+home = $(HOME)
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
@@ -57,9 +57,9 @@
 # | The name of the libraries to be created/linked to |
 # %---------------------------------------------------%
 #
-ARPACKLIB  = $(home)/libarpack_$(PLAT).a
-LAPACKLIB = 
-BLASLIB = 
+ARPACKLIB  = $(home)/libarpack.a
+LAPACKLIB = $(home)/liblapack.a
+BLASLIB = $(home)/libblas.a
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
