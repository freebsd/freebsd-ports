--- bin/macros_FreeBSD.mk.orig	2008-04-23 11:32:13.000000000 +0200
+++ bin/macros_FreeBSD.mk	2008-04-29 23:49:19.000000000 +0200
@@ -1,3 +1,4 @@
+# $FreeBSD$
 #============================================================================
 #
 #                    Code_Saturne version 1.3
@@ -29,13 +30,13 @@
 #
 #============================================================================
 #
-# Macros du Makefile Code_Saturne pour Linux
-############################################
+# Macros du Makefile Code_Saturne pour FreeBSD
+##############################################
 #
 # Macro pour BFT
 #---------------
 
-BFT_HOME        =/home/saturne/opt/bft-1.0.6/arch/Linux
+BFT_HOME        =${LOCALBASE}
 
 BFT_INC         =-I$(BFT_HOME)/include
 BFT_LDFLAGS     =-L$(BFT_HOME)/lib -lbft
@@ -43,7 +44,7 @@
 # Macro pour FVM
 #---------------
 
-FVM_HOME        =/home/saturne/opt/fvm-0.10.0/arch/Linux
+FVM_HOME        =${LOCALBASE}
 
 FVM_INC         =-I$(FVM_HOME)/include
 FVM_LDFLAGS     =-L$(FVM_HOME)/lib -lfvm
@@ -56,10 +57,9 @@
 MPE             =0
 MPE_COMM        =0
 
-# Pour Open MPI sur saturne
-MPI_HOME        =/home/saturne/opt/openmpi-1.2.5/arch/Linux
-MPI_INC         =-isystem$(MPI_HOME)/include
-MPI_LIB         =-pthread -L$(MPI_HOME)/lib -lmpi -lopen-rte -lopen-pal -ldl -Wl,--export-dynamic -lnsl -lutil -lm -ldl
+# Pour MPI sur saturne
+MPI_INC         =-I$(MPI_HOME)/include
+MPI_LIB         =-L$(MPI_HOME)/lib ${MPI_LIBS} $(PTHREAD_LIBS)
 
 # Macro pour Sockets
 #-------------------
@@ -75,7 +75,7 @@
 # Option XML
 XML             =1
 
-XML_HOME = /usr
+XML_HOME = ${LOCALBASE}
 
 XML_INC  =-I$(XML_HOME)/include/libxml2
 XML_LIB  =-L$(XML_HOME)/lib -lxml2
@@ -84,11 +84,10 @@
 #----------------
 
 # Option BLAS
-BLAS            =1
-BLAS_HOME       =/home/saturne/opt/atlas-3.8.0/arch/Linux_P4E
-BLAS_INC        =-I$(BLAS_HOME)/include
+BLAS            =0
+BLAS_INC        =
 BLAS_CFLAGS     =-D_CS_HAVE_CBLAS
-BLAS_LDFLAGS    =-L$(BLAS_HOME)/lib -lcblas -latlas
+BLAS_LDFLAGS    =
 
 
 # Preprocesseur
@@ -101,35 +100,35 @@
 # Compilateur C
 #--------------
 
-CCOMP                  = /home/saturne/opt/gcc-4.2.3/arch/Linux/bin/gcc
+CCOMP                  = $(CC)
 
 CCOMPFLAGSDEF          = -std=c99 -funsigned-char -pedantic -W -Wall -Wshadow \
                          -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings \
                          -Wstrict-prototypes -Wmissing-prototypes \
-                         -Wmissing-declarations -Wnested-externs -Wno-uninitialized 
+                         -Wmissing-declarations -Wnested-externs -Wno-uninitialized
 
-CCOMPFLAGS             = $(CCOMPFLAGSDEF) -O -Wno-unused
-CCOMPFLAGSOPTPART1     = $(CCOMPFLAGSDEF) -O2
-CCOMPFLAGSOPTPART2     = $(CCOMPFLAGSDEF) -O2
-CCOMPFLAGSOPTPART3     = $(CCOMPFLAGSDEF) -O0
-CCOMPFLAGSLO           = $(CCOMPFLAGSDEF) -O0            
-CCOMPFLAGSDBG          = $(CCOMPFLAGSDEF) -g3            
+CCOMPFLAGS             = $(CCOMPFLAGSDEF) $(CFLAGS) -Wno-unused
+CCOMPFLAGSOPTPART1     = $(CCOMPFLAGSDEF) $(CFLAGS)
+CCOMPFLAGSOPTPART2     = $(CCOMPFLAGSDEF) $(CFLAGS)
+CCOMPFLAGSOPTPART3     = $(CCOMPFLAGSDEF) $(CFLAGS)
+CCOMPFLAGSLO           = $(CCOMPFLAGSDEF) -O0
+CCOMPFLAGSDBG          = $(CCOMPFLAGSDEF) -g
 CCOMPFLAGSPROF         = -pg
-CCOMPFLAGSVERS         = -v            
+CCOMPFLAGSVERS         = -v
 
 
-# Compilateur FORTRAN 
+# Compilateur FORTRAN
 #--------------------
 #  Profiling gprof : -pg -a
 
-FTNCOMP                = /home/saturne/opt/gcc-4.2.3/arch/Linux/bin/gfortran
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
@@ -142,13 +141,13 @@
 
 # Linker
 
-LDEDL           = /home/saturne/opt/gcc-4.2.3/arch/Linux/bin/gfortran
-LDEDLFLAGS      = -O
-LDEDLFLAGSLO    = -O0
+LDEDL           = $(FC)
+LDEDLFLAGS      = $(LDFLAGS)
+LDEDLFLAGSLO    = $(LDFLAGS)
 LDEDLFLAGSDBG   = -g
 LDEDLFLAGSPROF  = -pg
 LDEDLFLAGSVERS  = -v
-LDEDLRPATH      = -rdynamic -Wl,-rpath -Wl,/home/saturne/opt/gcc-4.2.3/arch/Linux/lib:
+LDEDLRPATH      = -rdynamic -Wl,-rpath -Wl,
 
 
 # Positionnement des variables pour le pre-processeur
@@ -164,7 +163,7 @@
 
 # Librairies de base toujours prises en compte
 
-LIBBASIC = $(BFT_LDFLAGS) $(FVM_LDFLAGS) -lm -lpthread
+LIBBASIC = $(BFT_LDFLAGS) $(FVM_LDFLAGS) -lm $(PTHREAD_LIBS)
 
 # Librairies en mode sans option
 
@@ -180,7 +179,7 @@
 
 # Librairie en mode ElectricFence (malloc debugger)
 
-LIBEF    =-L/home/saturne/opt/efence-2.1.14/arch/Linux/lib -lefence
+LIBEF    =-L${LOCALBASE}/lib -lefence
 
 # Liste eventuelle des fichiers a compiler avec des options particulieres
 #------------------------------------------------------------------------
