--- bin/macros_FreeBSD.mk.orig	2008-11-05 18:48:56.000000000 +0100
+++ bin/macros_FreeBSD.mk	2009-01-25 10:37:09.000000000 +0100
@@ -1,3 +1,4 @@
+# $FreeBSD$
 #============================================================================
 #
 #                    Code_Saturne version 1.3
@@ -29,13 +30,13 @@
 #
 #============================================================================
 #
-# Macros for Makefile under Linux x86
-#####################################
+# Macros for Makefile under FreeBSD
+###################################
 #
 # Macros for BFT
 #---------------
 
-BFT_HOME        =/home/saturne/opt/bft-1.0.8/arch/Linux
+BFT_HOME        =${LOCALBASE}
 
 BFT_INC         =-I$(BFT_HOME)/include
 BFT_LDFLAGS     =-L$(BFT_HOME)/lib -lbft
@@ -43,7 +44,7 @@
 # Macros for FVM
 #---------------
 
-FVM_HOME        =/home/saturne/opt/fvm-0.12.0/arch/Linux
+FVM_HOME        =${LOCALBASE}
 
 FVM_INC         =-I$(FVM_HOME)/include
 FVM_LDFLAGS     =-L$(FVM_HOME)/lib -lfvm
@@ -56,10 +57,9 @@
 MPE             =0
 MPE_COMM        =0
 
-# For Open MPI on saturne
-MPI_HOME        =/home/saturne/opt/openmpi-1.2.6/arch/Linux
+# For MPI on saturne
 MPI_INC         =-I$(MPI_HOME)/include
-MPI_LIB         =-pthread -L$(MPI_HOME)/lib -lmpi -lopen-rte -lopen-pal -ldl -Wl,--export-dynamic -lnsl -lutil -lm -ldl
+MPI_LIB         =-L$(MPI_HOME)/lib ${MPI_LIBS} $(PTHREAD_LIBS)
 
 # Macros for Sockets
 #-------------------
@@ -75,20 +75,19 @@
 # XML support
 XML             =1
 
-XML_HOME =
+XML_HOME = ${LOCALBASE}
 
-XML_INC  =-I/usr/include/libxml2
-XML_LIB  =-lxml2
+XML_INC  =-I$(XML_HOME)/include/libxml2
+XML_LIB  =-L$(XML_HOME)/lib -lxml2
 
 # Macros for BLAS
 #----------------
 
 # BLAS support
-BLAS            =1
-BLAS_HOME       =
-BLAS_INC        =-I/usr/include
+BLAS            =0
+BLAS_INC        =
 BLAS_CFLAGS     =-D_CS_HAVE_CBLAS
-BLAS_LDFLAGS    =-lcblas -latlas
+BLAS_LDFLAGS    =
 
 # Macros for gettext
 #-------------------
@@ -110,19 +109,19 @@
 # C compiler
 #-----------
 
-CCOMP                  = /home/saturne/opt/gcc-4.3.1/arch/Linux/bin/gcc
+CCOMP                  = $(CC)
 
 CCOMPFLAGSDEF          = -std=c99 -funsigned-char -pedantic -W -Wall -Wshadow \
                          -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings \
                          -Wstrict-prototypes -Wmissing-prototypes \
                          -Wmissing-declarations -Wnested-externs -Wno-uninitialized
 
-CCOMPFLAGS             = $(CCOMPFLAGSDEF) -O -Wno-unused
-CCOMPFLAGSOPTPART1     = $(CCOMPFLAGSDEF) -O2
-CCOMPFLAGSOPTPART2     = $(CCOMPFLAGSDEF) -O2
-CCOMPFLAGSOPTPART3     = $(CCOMPFLAGSDEF) -O0
+CCOMPFLAGS             = $(CCOMPFLAGSDEF) $(CFLAGS) -Wno-unused
+CCOMPFLAGSOPTPART1     = $(CCOMPFLAGSDEF) $(CFLAGS)
+CCOMPFLAGSOPTPART2     = $(CCOMPFLAGSDEF) $(CFLAGS)
+CCOMPFLAGSOPTPART3     = $(CCOMPFLAGSDEF) $(CFLAGS)
 CCOMPFLAGSLO           = $(CCOMPFLAGSDEF) -O0
-CCOMPFLAGSDBG          = $(CCOMPFLAGSDEF) -g3
+CCOMPFLAGSDBG          = $(CCOMPFLAGSDEF) -g
 CCOMPFLAGSPROF         = -pg
 CCOMPFLAGSVERS         = -v
 
@@ -131,14 +130,14 @@
 #-----------------
 #  Profiling gprof : -pg -a
 
-FTNCOMP                = /home/saturne/opt/gcc-4.3.1/arch/Linux/bin/gfortran
+FTNCOMP                = $(FC)
 
 FTNCOMPFLAGSDEF        = -I.
 
-FTNCOMPFLAGS           = $(FTNCOMPFLAGSDEF) -O1
-FTNCOMPFLAGSOPTPART1   = $(FTNCOMPFLAGSDEF) -O2
-FTNCOMPFLAGSOPTPART2   = $(FTNCOMPFLAGSDEF) -O3
-FTNCOMPFLAGSOPTPART3   = $(FTNCOMPFLAGSDEF) -O0
+FTNCOMPFLAGS           = $(FTNCOMPFLAGSDEF) $(FFLAGS)
+FTNCOMPFLAGSOPTPART1   = $(FTNCOMPFLAGSDEF) $(FFLAGS)
+FTNCOMPFLAGSOPTPART2   = $(FTNCOMPFLAGSDEF) $(FFLAGS)
+FTNCOMPFLAGSOPTPART3   = $(FTNCOMPFLAGSDEF) $(FFLAGS)
 FTNCOMPFLAGSLO         = $(FTNCOMPFLAGSDEF) -O0
 FTNCOMPFLAGSDBG        = $(FTNCOMPFLAGSDEF) -g
 FTNCOMPFLAGSPROF       = -pg
@@ -152,12 +151,12 @@
 # Linker
 
 LDEDL           = $(FTNCOMP)
-LDEDLFLAGS      = -O
-LDEDLFLAGSLO    = -O0
+LDEDLFLAGS      = $(LDFLAGS)
+LDEDLFLAGSLO    = $(LDFLAGS)
 LDEDLFLAGSDBG   = -g
 LDEDLFLAGSPROF  = -pg
 LDEDLFLAGSVERS  = -v
-LDEDLRPATH      = -rdynamic -Wl,-rpath -Wl,/home/saturne/opt/gcc-4.3.1/arch/Linux/lib:
+LDEDLRPATH      = -rdynamic -Wl,-rpath -Wl,${LOCALBASE}/lib:
 
 
 # Set preprocessor variables
@@ -172,7 +171,7 @@
 
 # Base libraries (always used)
 
-LIBBASIC = $(BFT_LDFLAGS) $(FVM_LDFLAGS) -lm -lpthread
+LIBBASIC = $(BFT_LDFLAGS) $(FVM_LDFLAGS) -lm $(PTHREAD_LIBS)
 
 # Libraries in production mode
 
@@ -188,7 +187,7 @@
 
 # Library in ElectricFence (malloc debugger) mode
 
-LIBEF    =-L/home/saturne/opt/efence-2.1.14/arch/Linux/lib -lefence
+LIBEF    =-L${LOCALBASE}/lib -lefence
 
 # Optional lists of files to compile with specific options
 #---------------------------------------------------------
