--- make.inc.orig	Thu Nov 30 22:18:37 2000
+++ make.inc	Sun Aug 29 14:46:46 2004
@@ -3,8 +3,8 @@
 #     UNI-C, Denmark; Univ. of Tennessee, USA; NAG Ltd., UK
 #     August 5, 2000
 #
-FC	 = f95 -free
-FC1      = f95 -fixed
+FC	 = %%FC%% %%FORTRAN_FIXED%%
+FC1      = %%FC%% %%FORTRAN_FREE%%
 # -dcfuns  Enable recognition of non-standard double
 #          precision  complex intrinsic functions
 # -dusty   Allows the compilation and execution of "legacy"
@@ -13,14 +13,14 @@
 # -ieee=full enables all IEEE arithmetic facilities
 #          including non-stop arithmetic.
 
-OPTS0    = -u -V -dcfuns -dusty -ieee=full
+OPTS0    = %%FFOPTFLAGS%% #-u -V -dcfuns -dusty -ieee=full
 MODLIB   = -I./../lapack95_modules
 OPTS1    = -c $(OPTS0)
 OPTS3    = $(OPTS1) $(MODLIB)
 OPTL     = -o 
 OPTLIB   =
 
-LAPACK_PATH = /usr/local/lib/LAPACK3/
+LAPACK_PATH = %%LOCALBASE%%/lib
 
 LAPACK95 = ../lapack95.a
 LAPACK77 = $(LAPACK_PATH)/lapack.a
