--- Makefile.inc.orig	Wed Apr  5 14:00:59 2000
+++ Makefile.inc	Mon Oct 20 21:56:56 2003
@@ -1,25 +1,27 @@
-# ARPACK++ v1.2 2/18/2000
+# ARPACK++ v1.2 2/20/2000
+# $FreeBSD$
 # c++ interface to ARPACK code.
 # This file contains some definitions used to compile arpack++ examples
-# with the g++ compiler under Sun Solaris.
+# with the g++ compiler under FreeBSD.
 
 
 # Defining the machine.
 
-PLAT         = solaris
+PLAT         = `uname -s`
 
 # Defining the compiler.
 
-CPP          = g++
+CPP          = $(CXX)
 
 # Defining ARPACK++ directories.
 # ARPACKPP_INC is the directory that contains all arpack++ header files.
 # SUPERLU_DIR and UMFPACK_DIR must be set to ARPACKPP_INC.
 
-ARPACKPP_DIR = $(HOME)/arpack++
-ARPACKPP_INC = $(ARPACKPP_DIR)/include
-SUPERLU_DIR  = $(ARPACKPP_INC)
-UMFPACK_DIR  = $(ARPACKPP_INC)
+ARPACK_INC   = %%LOCALBASE%%/include
+ARPACKPP_DIR = %%LOCALBASE%%
+ARPACKPP_INC = $(ARPACKPP_DIR)/include/ARPACK++
+SUPERLU_DIR  = %%LOCALBASE%%/include/superlu
+UMFPACK_DIR  = %%LOCALBASE%%/include/UMFPACK
 
 # Defining ARPACK, LAPACK, UMFPACK, SUPERLU, BLAS and FORTRAN libraries.
 # See the arpack++ manual or the README file for directions on how to 
@@ -33,31 +35,26 @@
 # Other libraries should be defined if the user intends to compile
 # arpack++ on another environment.
 
-ARPACK_LIB   = $(HOME)/lib/arpack_$(PLAT).a
-LAPACK_LIB   = /opt/LAPACK/lapack_$(PLAT).a
-UMFPACK_LIB  = $(HOME)/lib/umfpack_$(PLAT).a
-SUPERLU_LIB  = $(HOME)/lib/superlu_$(PLAT).a
-BLAS_LIB     = /opt/LAPACK/blas_$(PLAT).a 
-FORTRAN_LIBS = /opt/SUNWspro/SC4.0/lib/libF77.a \
-               /opt/SUNWspro/SC4.0/lib/libM77.a \
-               /opt/SUNWspro/SC4.0/lib/libsunmath.a
+ARPACK_LIB   = %%LOCALBASE%%/lib/libarpack.a
+LAPACK_LIB   = %%LOCALBASE%%/lib/liblapack.a
+UMFPACK_LIB  = %%LOCALBASE%%/lib/libumfpack.a
+SUPERLU_LIB  = %%LOCALBASE%%/lib/libsuperlu.a
+BLAS_LIB     = %%LOCALBASE%%/lib/libf77blas.a %%LOCALBASE%%/lib/libatlas.a
+FORTRAN_LIBS = -lg2c
 
 # Defining g++ flags and directories.
 
-# CPP_WARNINGS = -fpermissive 
-CPP_WARNINGS = -Wall -ansi -pedantic-errors
+CPP_WARNINGS = -Wno-deprecated
 CPP_DEBUG    = -g
-CPP_OPTIM    = -O
-CPP_LIBS     = 
-CPP_INC      = /usr/local/include/g++-3
+#CPP_OPTIM    = -O
+CPP_LIBS     = -lm
+CPP_INC      = %%LOCALBASE%%/include
 
-CPP_FLAGS    = $(CPP_DEBUG) -D$(PLAT) -I$(ARPACKPP_INC) -I$(CPP_INC) \
-               $(CPP_WARNINGS)
+CPP_FLAGS    = $(CXXFLAGS) $(CPP_WARNINGS) -D$(PLAT) -I$(ARPACKPP_INC) -I$(CPP_INC)
 
 # Putting all libraries together.
 
-ALL_LIBS     = $(CPP_LIBS) $(ARPACK_LIB) $(LAPACK_LIB) \
-               $(BLAS_LIB) $(FORTRAN_LIBS) 
+ALL_LIBS     = $(ARPACK_LIB) $(LAPACK_LIB) $(BLAS_LIB) $(FORTRAN_LIBS) $(CPP_LIBS)
 
 # defining paths.
 
