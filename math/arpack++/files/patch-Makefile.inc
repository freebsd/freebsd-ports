--- Makefile.inc.orig	2008-12-12 15:10:18.000000000 +0100
+++ Makefile.inc	2008-12-12 15:12:13.000000000 +0100
@@ -1,26 +1,26 @@
-# ARPACK++ v1.2 2/18/2000
+# ARPACK++ v1.2 2/20/2000
 # c++ interface to ARPACK code.
 # This file contains some definitions used to compile arpack++ examples
-# with the g++ compiler under Sun Solaris.
+# with the g++ compiler under FreeBSD.
 
 
 # Defining the machine.
 
-PLAT         = linux
+PLAT         = `uname -s`
 
 # Defining the compiler.
 
-CPP          = g++
+CPP          = $(CXX)
 
 # Defining ARPACK++ directories.
 # ARPACKPP_INC is the directory that contains all arpack++ header files.
 # SUPERLU_DIR and UMFPACK_DIR must be set to ARPACKPP_INC.
 
-#ARPACKPP_DIR = $(HOME)/arpack++
-ARPACKPP_DIR = ../../..
-ARPACKPP_INC = $(ARPACKPP_DIR)/include
-SUPERLU_DIR  = $(ARPACKPP_INC)
-UMFPACK_DIR  = $(ARPACKPP_INC)
+ARPACK_INC   = /usr/local/include
+ARPACKPP_DIR = /usr/local
+ARPACKPP_INC = $(ARPACKPP_DIR)/include/ARPACK++
+SUPERLU_DIR  = /usr/local/include/superlu
+UMFPACK_DIR  = /usr/local/include/UMFPACK
 
 # Defining ARPACK, LAPACK, UMFPACK, SUPERLU, BLAS and FORTRAN libraries.
 # See the arpack++ manual or the README file for directions on how to 
@@ -34,29 +35,26 @@
 # Other libraries should be defined if the user intends to compile
 # arpack++ on another environment.
 
-ARPACK_LIB   = -larpack
-LAPACK_LIB   = -llapack
-UMFPACK_LIB  = #-lumfpack
-SUPERLU_LIB  = /usr/lib/libsuperlu.a
-BLAS_LIB     = -lblas
-FORTRAN_LIBS = -lg2c
+ARPACK_LIB   = /usr/local/lib/libarpack.a
+LAPACK_LIB   = /usr/local/lib/liblapack.a
+UMFPACK_LIB  = /usr/local/lib/libumfpack.a
+SUPERLU_LIB  = /usr/local/lib/libsuperlu.so
+BLAS_LIB     = /usr/local/lib/libf77blas.a /usr/local/lib/libatlas.a
+FORTRAN_LIBS = -L/usr/local/lib/gcc-4.2.5 -lgfortran
 
 # Defining g++ flags and directories.
 
-# CPP_WARNINGS = -fpermissive 
-CPP_WARNINGS = -Wall -ansi -pedantic-errors
+CPP_WARNINGS = -Wno-deprecated
 CPP_DEBUG    = -g
-CPP_OPTIM    = -O
-CPP_LIBS     = 
-CPP_INC      = 
+#CPP_OPTIM    = -O
+CPP_LIBS     = -lm
+CPP_INC      = /usr/local/include
 
-CPP_FLAGS    = $(CPP_DEBUG) -D$(PLAT) -I$(ARPACKPP_INC) -I$(CPP_INC) \
-               $(CPP_WARNINGS)
+CPP_FLAGS    = $(CXXFLAGS) $(CPP_WARNINGS) -D$(PLAT) -I$(ARPACKPP_INC) -I$(CPP_INC)
 
 # Putting all libraries together.
 
-ALL_LIBS     = $(CPP_LIBS) $(ARPACK_LIB) $(LAPACK_LIB) \
-               $(BLAS_LIB) $(FORTRAN_LIBS) 
+ALL_LIBS     = $(ARPACK_LIB) $(LAPACK_LIB) $(BLAS_LIB) $(FORTRAN_LIBS) $(CPP_LIBS)
 
 # defining paths.
 
