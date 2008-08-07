--- fortran/cfortran.h.orig	2008-07-23 21:47:30.000000000 -0500
+++ fortran/cfortran.h	2008-07-23 21:48:50.000000000 -0500
@@ -134,7 +134,8 @@
 /* Split #if into 2 because some HP-UX can't handle long #if */
 #if !(defined(NAGf90Fortran)||defined(f2cFortran)||defined(hpuxFortran)||defined(apolloFortran)||defined(sunFortran)||defined(IBMR2Fortran)||defined(CRAYFortran)||defined(PATHSCALE_COMPILER)||defined(gFortran))
 #if !(defined(mipsFortran)||defined(DECFortran)||defined(vmsFortran)||defined(CONVEXFortran)||defined(PowerStationFortran)||defined(AbsoftUNIXFortran)||defined(AbsoftProFortran)||defined(SXFortran))
-/* If your compiler barfs on ' #error', replace # with the trigraph for #     */
+#define    f2cFortran 
+/* If your compiler barfs on ' #error', replace # with the trigraph for #
  #error "cfortran.h:  Can't find your environment among:\
     - MIPS cc and f77 2.0. (e.g. Silicon Graphics, DECstations, ...)     \
     - IBM AIX XL C and FORTRAN Compiler/6000 Version 01.01.0000.0000     \
@@ -158,7 +159,7 @@
     - Absoft Pro Fortran: Use #define AbsoftProFortran \
     - Portland Group Fortran: Use #define pgiFortran \
     - PathScale Fortran: Use #define PATHSCALE_COMPILER"
-/* Compiler must throw us out at this point! */
+   Compiler must throw us out at this point! */
 #endif
 #endif
 
