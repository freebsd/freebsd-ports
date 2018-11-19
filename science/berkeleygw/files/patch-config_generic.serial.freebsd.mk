--- config/generic.serial.freebsd.mk.orig	2018-06-01 08:57:02 UTC
+++ config/generic.serial.freebsd.mk
@@ -19,24 +19,24 @@ MATHFLAG  = -DUSEFFTW3 -DUNPACKED
 #DEBUGFLAG = -DDEBUG
 
 MAKE    = gmake
-FCPP    = cpp47 -C
-F90free = gfortran47 -ffree-form -ffree-line-length-none
-LINK    = gfortran47
+FCPP    = $(FREEBSD_PREFIX)/bin/cpp$(FREEBSD_GCC_DEFAULT) -C
+F90free = $(FC) -ffree-form -ffree-line-length-none
+LINK    = $(FC)
 FOPTS   = -O3
 FNOOPTS = $(FOPTS)
 MOD_OPT = -J
 INCFLAG = -I
 
-CC_COMP = g++47
-C_COMP  = gcc47
-C_LINK  = g++47
-C_OPTS  = -O3
+CC_COMP = $(CXX)
+C_COMP  = $(CC)
+C_LINK  = $(CXX)
+C_OPTS  = $(CFLAGS)
 C_DEBUGFLAG =
 
 REMOVE  = /bin/rm -f
 
 # Math Libraries
 #
-FFTWLIB      = -L/usr/local/lib/ -lfftw3
-FFTWINCLUDE  = /usr/local/include
-LAPACKLIB    = -L/usr/local/lib/ -llapack -lblas
+FFTWLIB      = -L$(FREEBSD_PREFIX)/lib/ -lfftw3
+FFTWINCLUDE  = $(FREEBSD_PREFIX)/include
+LAPACKLIB    = -L$(FREEBSD_PREFIX)/lib/ -lopenblas
