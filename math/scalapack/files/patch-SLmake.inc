--- SLmake.inc.orig	Thu Aug  9 11:59:50 2001
+++ SLmake.inc		Mon May  5 11:51:11 2003
@@ -19,26 +19,26 @@
 #  The complete path to the top level of ScaLAPACK directory, usually
 #  $(HOME)/SCALAPACK
 #
-home          = $(HOME)/SCALAPACK
+home          = @WRKSRC@
 #
 #  The platform identifier to suffix to the end of library names
 #
-PLAT          = LINUX
+PLAT          = FreeBSD
 #
 #  BLACS setup.  All version need the debug level (0 or 1),
 #  and the directory where the BLACS libraries are
 #
 BLACSDBGLVL   = 0
-BLACSdir      = /usr/local/lib
+BLACSdir      = @PREFIX@/lib
 #
 #  MPI setup; tailor to your system if using MPIBLACS
 #  Will need to comment out these 6 lines if using PVM
 #
 USEMPI        = -DUsingMpiBlacs
-SMPLIB        = /usr/local/mpich-1.2.1/lib/libmpich.a
-BLACSFINIT    = $(BLACSdir)/libmpiblacsF77init-p4.a
-BLACSCINIT    = $(BLACSdir)/libmpiblacsCinit-p4.a
-BLACSLIB      = $(BLACSdir)/libmpiblacs-p4.a
+SMPLIB        = @PREFIX@/mpich/lib/libmpich.a @PREFIX@/mpich/lib/libpmpich.a
+BLACSFINIT    = $(BLACSdir)/libblacsf77.a
+BLACSCINIT    = $(BLACSdir)/libblacsc.a
+BLACSLIB      = $(BLACSdir)/libblacs.a
 TESTINGdir    = $(home)/TESTING
 
 #
@@ -67,12 +67,12 @@
 #
 #  The fortran and C compilers, loaders, and their flags
 #
-F77           = g77
+F77           = @F77@
 #F77           = /usr/local/pgi/linux86/bin/pgf77
-CC            = gcc
+CC            = @CC@
 NOOPT         = 
-F77FLAGS      =  -O3 $(NOOPT)
-CCFLAGS       = -O4
+F77FLAGS      = @FFLAGS@
+CCFLAGS       = @CFLAGS@
 SRCFLAG       =
 F77LOADER     = $(F77)
 CCLOADER      = $(CC)
@@ -94,7 +94,7 @@
 #  The name of the libraries to be created/linked to
 #
 SCALAPACKLIB  = $(home)/libscalapack.a
-BLASLIB       = /usr/local/lib/libf77blas.a /usr/local/lib/libatlas.a
+BLASLIB       = @PREFIX@/lib/libf77blas.a @PREFIX@/lib/libatlas.a
 #
 PBLIBS        = $(SCALAPACKLIB) $(FBLACSLIB) $(BLASLIB) $(SMPLIB)
 PRLIBS        = $(SCALAPACKLIB) $(CBLACSLIB) $(SMPLIB)
