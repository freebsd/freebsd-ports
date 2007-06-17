--- bin/macros_FreeBSD.mk.orig	Thu Mar  1 12:23:39 2007
+++ bin/macros_FreeBSD.mk	Tue May  8 15:06:34 2007
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
 
-BFT_HOME        =/home/saturne/opt/bft-1.0.3/arch/Linux
+BFT_HOME        =${LOCALBASE}
 
 BFT_INC         =-I$(BFT_HOME)/include
 BFT_LDFLAGS     =-L$(BFT_HOME)/lib -lbft
@@ -43,7 +44,7 @@
 # Macro pour FVM
 #---------------
 
-FVM_HOME        =/home/saturne/opt/fvm-0.6.3/arch/Linux
+FVM_HOME        =${LOCALBASE}
 
 FVM_INC         =-I$(FVM_HOME)/include
 FVM_LDFLAGS     =-L$(FVM_HOME)/lib -lfvm
@@ -57,9 +58,8 @@
 MPE_COMM        =1
 
 # Pour Open MPI sur saturne
-MPI_HOME        =/home/saturne/opt/openmpi-1.1.1/arch/Linux
-MPI_INC         =-isystem$(MPI_HOME)/include
-MPI_LIB         =-pthread -L$(MPI_HOME)/lib -lmpi -lorte -lopal -ldl -Wl,--export-dynamic -lnsl -lutil -lm -ldl 
+MPI_INC         =-I$(MPI_HOME)/include
+MPI_LIB         =-L$(MPI_HOME)/lib ${MPI_LIBS} $(PTHREAD_LIBS)
 
 
 # Macro pour Sockets
@@ -76,10 +76,10 @@
 # Option XML
 XML             =1
 
-XML_HOME = /home/saturne/opt/libxml2-2.6.19
+XML_HOME =${LOCALBASE}
 
 XML_INC  =-I$(XML_HOME)/include/libxml2
-XML_LIB  =-L$(XML_HOME)/arch/Linux/lib -lxml2
+XML_LIB  =-L$(XML_HOME)/lib -lxml2
 
 
 # Macro pour BLAS
@@ -100,36 +100,36 @@
 # Compilateur C natif
 #--------------------
 
-CCOMP                  = /home/saturne/opt/gcc-4.1.1/arch/Linux/bin/gcc
+CCOMP                  = $(CC)
 
 CCOMPFLAGSDEF          = -std=c99 -funsigned-char -pedantic -W -Wall -Wshadow \
                          -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings \
                          -Wstrict-prototypes -Wmissing-prototypes \
-                         -Wmissing-declarations -Wnested-externs -Wno-uninitialized 
+                         -Wmissing-declarations -Wnested-externs -Wno-uninitialized
 
-CCOMPFLAGS             = $(CCOMPFLAGSDEF) -O -Wno-unused
-CCOMPFLAGSOPTPART1     = $(CCOMPFLAGSDEF) -O              
-CCOMPFLAGSOPTPART2     = $(CCOMPFLAGSDEF) -O 
-CCOMPFLAGSOPTPART3     = $(CCOMPFLAGSDEF) -O 
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
 
 
 # Compilateur FORTRAN 
 #--------------------
 #  Profiling gprof : -pg -a
 
-FTNCOMP                = /home/saturne/opt/gcc-4.1.1/arch/Linux/bin/gfortran
+FTNCOMP                = $(FC)
 
 FTNCOMPFLAGSDEF        = -I.
 
-FTNCOMPFLAGS           = $(FTNCOMPFLAGSDEF) -O1
-FTNCOMPFLAGSOPTPART1   = $(FTNCOMPFLAGSDEF) -O2
-FTNCOMPFLAGSOPTPART2   = $(FTNCOMPFLAGSDEF) -O6
-FTNCOMPFLAGSOPTPART3   = $(FTNCOMPFLAGSDEF) -O0
-FTNCOMPFLAGSLO         = $(FTNCOMPFLAGSDEF) -O0
+FTNCOMPFLAGS           = $(FTNCOMPFLAGSDEF) $(FFLAGS)
+FTNCOMPFLAGSOPTPART1   = $(FTNCOMPFLAGSDEF) $(FFLAGS)
+FTNCOMPFLAGSOPTPART2   = $(FTNCOMPFLAGSDEF) $(FFLAGS)
+FTNCOMPFLAGSOPTPART3   = $(FTNCOMPFLAGSDEF) $(FFLAGS)
+FTNCOMPFLAGSLO         = $(FTNCOMPFLAGSDEF) $(FFLAGS)
 FTNCOMPFLAGSDBG        = $(FTNCOMPFLAGSDEF) -g
 FTNCOMPFLAGSPROF       = -pg
 FTNCOMPFLAGSVERS       = -v
@@ -140,13 +140,13 @@
 
 # Linker
 
-LDEDL           = /home/saturne/opt/gcc-4.1.1/arch/Linux/bin/gfortran
-LDEDLFLAGS      = -O
-LDEDLFLAGSLO    = -O0
+LDEDL           = $(FC)
+LDEDLFLAGS      = $(LDFLAGS)
+LDEDLFLAGSLO    = $(LDFLAGS)
 LDEDLFLAGSDBG   = -g
 LDEDLFLAGSPROF  = -pg
 LDEDLFLAGSVERS  = -v
-LDEDLRPATH      = -rdynamic -Wl,-rpath -Wl,/home/saturne/opt/gcc-4.1.1/arch/Linux/lib:
+LDEDLRPATH      = -rdynamic -Wl,-rpath -Wl,
 
 
 # Positionnement des variables pour le pre-processeur
@@ -162,7 +162,7 @@
 
 # Librairies de base toujours prises en compte
 
-LIBBASIC = $(BFT_LDFLAGS) $(FVM_LDFLAGS) -lm -lpthread
+LIBBASIC = $(BFT_LDFLAGS) $(FVM_LDFLAGS) -lm $(PTHREAD_LIBS)
 
 # Librairies en mode sans option
 
@@ -178,7 +178,7 @@
 
 # Librairie en mode ElectricFence (malloc debugger)
 
-LIBEF    =-L/home/saturne/opt/efence-2.1.14/arch/Linux/lib -lefence
+LIBEF    =-L${LOCALBASE}/lib -lefence
 
 # Liste eventuelle des fichiers a compiler avec des options particulieres
 #------------------------------------------------------------------------
