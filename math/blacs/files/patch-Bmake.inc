--- Bmake.inc.orig	Mon May  5 10:53:00 2003
+++ Bmake.inc	Mon May  5 10:58:38 2003
@@ -13,7 +13,7 @@
 #  -----------------------------
 #  The top level BLACS directory
 #  -----------------------------
-   BTOPdir = $(HOME)/BLACS
+   BTOPdir = @WRKSRC@
 
 #  ---------------------------------------------------------------------------
 #  The communication library your BLACS have been written for.
@@ -32,14 +32,14 @@
 #  -------------------------------------------------------------
 #  The platform identifier to suffix to the end of library names
 #  -------------------------------------------------------------
-   PLAT = LINUX
+   PLAT = FreeBSD
 
 #  ----------------------------------------------------------
 #  Name and location of the BLACS library.  See section 2 for 
 #  details on BLACS debug level (BLACSDBGLVL).
 #  ----------------------------------------------------------
    BLACSdir    = $(BTOPdir)/LIB
-   BLACSDBGLVL = 0
+   BLACSDBGLVL = @DEBUG_LEVEL@
    BLACSFINIT  = $(BLACSdir)/blacsF77init_$(COMMLIB)-$(PLAT)-$(BLACSDBGLVL).a
    BLACSCINIT  = $(BLACSdir)/blacsCinit_$(COMMLIB)-$(PLAT)-$(BLACSDBGLVL).a
    BLACSLIB    = $(BLACSdir)/blacs_$(COMMLIB)-$(PLAT)-$(BLACSDBGLVL).a
@@ -47,10 +47,10 @@
 #  -------------------------------------
 #  Name and location of the MPI library.
 #  -------------------------------------
-   MPIdir = /usr/local/mpich
+   MPIdir = @PREFIX@/mpich
    MPILIBdir = $(MPIdir)/lib/
    MPIINCdir = $(MPIdir)/include
-   MPILIB = $(MPILIBdir)/libmpich.a
+   MPILIB = $(MPILIBdir)/libmpich.a $(MPILIBdir)/libpmpich.a
 
 #  -------------------------------------
 #  All libraries required by the tester.
@@ -195,16 +195,15 @@
 #  optimization.  This is the F77NO_OPTFLAG.  The usage of the remaining
 #  macros should be obvious from the names.
 #=============================================================================
-   F77            = g77
-   F77NO_OPTFLAGS = 
-   F77FLAGS       = $(F77NO_OPTFLAGS) -O
-   F77LOADER      = $(F77)
+   F77            = @F77@
+   F77NO_OPTFLAGS = @F77EXTRAFLAGS@
+   F77FLAGS       = @FFLAGS@
+   F77LOADER      = @F77@
    F77LOADFLAGS   = 
-   CC             = gcc
-   CCFLAGS        = -O4
+   CC             = @CC@
+   CCFLAGS        = @CFLAGS@
    CCLOADER       = $(CC)
    CCLOADFLAGS    = 
-
 #  --------------------------------------------------------------------------
 #  The archiver and the flag(s) to use when building an archive (library).
 #  Also the ranlib routine.  If your system has no ranlib, set RANLIB = echo.
