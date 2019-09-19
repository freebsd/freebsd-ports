--- Makefile.inc.orig	2015-11-23 03:58:51 UTC
+++ Makefile.inc
@@ -1,26 +1,26 @@
-# ARPACK++ v1.2 2/18/2000
+# ARPACK++ v2.3.0 9/1/2016
 # c++ interface to ARPACK code.
 # This file contains some definitions used to compile arpack++ examples
-# with the g++ compiler under linux.
+# with the c++ compiler under FreeBSD.
 
 
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
+ARPACK_INC   = %%LOCALBASE%%/include/arpack
+ARPACKPP_INC   = %%PREFIX%%/include/ARPACK++
+ARPACKPP_DIR = %%PREFIX%%/share/
+SUPERLU_DIR  = %%LOCALBASE%%/include/superlu
+UMFPACK_DIR  = %%LOCALBASE%%/include/suitesparse
 
 # Defining ARPACK, LAPACK, UMFPACK, SUPERLU, BLAS and FORTRAN libraries.
 # See the arpack++ manual or the README file for directions on how to 
@@ -37,49 +37,48 @@ UMFPACK_DIR  = $(ARPACKPP_INC)
 ARPACK_LIB   = -larpack
 LAPACK_LIB   = -llapack
 SUPERLU_LIB  = -lsuperlu
-BLAS_LIB     = -lblas
+BLAS_LIB     = %%BLAS%%
 FORTRAN_LIBS = -lgfortran
 
 # SuiteSparse contains the UMFPACK and CHOLMOD code. To link examples against 
 # these, set the SUITESPARSE_DIR to point to your installation:
-SUITESPARSE_DIR = $(ARPACKPP_DIR)/../SuiteSparse
+SUITESPARSE_DIR = %%LOCALBASE%%/include/suitesparse
 
-UMFPACK_LIB  = $(SUITESPARSE_DIR)/UMFPACK/Lib/libumfpack.a  \
- $(SUITESPARSE_DIR)/CHOLMOD/Lib/libcholmod.a \
- $(SUITESPARSE_DIR)/COLAMD/Lib/libcolamd.a \
- $(SUITESPARSE_DIR)/CCOLAMD/Lib/libccolamd.a \
- $(SUITESPARSE_DIR)/metis-4.0/libmetis.a  \
- $(SUITESPARSE_DIR)/CAMD/Lib/libcamd.a \
- $(SUITESPARSE_DIR)/AMD/Lib/libamd.a \
- $(SUITESPARSE_DIR)/SuiteSparse_config/libsuitesparseconfig.a 
+UMFPACK_LIB  = -lumfpack  \
+ -lcholmod \
+ -lcolamd \
+ -lccolamd \
+ -lmetis  \
+ -lcamd \
+ -lamd \
+ -lsuitesparseconfig 
  
-CHOLMOD_LIB  = $(SUITESPARSE_DIR)/CHOLMOD/Lib/libcholmod.a \
- $(SUITESPARSE_DIR)/COLAMD/Lib/libcolamd.a \
- $(SUITESPARSE_DIR)/CCOLAMD/Lib/libccolamd.a \
- $(SUITESPARSE_DIR)/metis-4.0/libmetis.a  \
- $(SUITESPARSE_DIR)/CAMD/Lib/libcamd.a \
- $(SUITESPARSE_DIR)/AMD/Lib/libamd.a \
+CHOLMOD_LIB  = -lcholmod \
+ -lcolamd \
+ -lccolamd \
+ -lmetis  \
+ -lcamd \
+ -lamd
 
 # For cholmod need additional headers:
-CHOLMOD_INC  = -I$(SUITESPARSE_DIR)/CHOLMOD/Include -I$(SUITESPARSE_DIR)/SuiteSparse_config
+CHOLMOD_INC  = -I$(SUITESPARSE_DIR)
 
 
 # Defining g++ flags and directories.
 
 # CPP_WARNINGS = -fpermissive 
-CPP_WARNINGS = -Wall -ansi -pedantic-errors
+#CPP_WARNINGS = -Wall -ansi -pedantic-errors
+CPP_WARNINGS = -Wno-deprecated
 CPP_DEBUG    = -g
 CPP_OPTIM    = -O
-CPP_LIBS     = 
+CPP_LIBS     = -lm
 CPP_INC      = 
 
-CPP_FLAGS    = $(CPP_DEBUG) -D$(PLAT) -I$(ARPACKPP_INC) -I$(CPP_INC) \
-               $(CPP_WARNINGS)
+CPP_FLAGS    = $(CXXFLAGS) $(CPP_WARNINGS) -D$(PLAT) -I$(ARPACKPP_INC) $(FCFLAGS)
 
 # Putting all libraries together.
 
-ALL_LIBS     = $(CPP_LIBS) $(ARPACK_LIB) \
-               $(BLAS_LIB) $(LAPACK_LIB) $(FORTRAN_LIBS) 
+ALL_LIBS     = $(LDFLAGS) $(ARPACK_LIB) $(LAPACK_LIB) $(BLAS_LIB) $(FORTRAN_LIBS) $(CPP_LIBS)
 
 # defining paths.
 
