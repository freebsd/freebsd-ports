--- make.inc	2000-11-30 22:18:37.000000000 +0900
+++ make.inc	2007-09-29 14:02:41.000000000 +0900
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
@@ -13,27 +13,27 @@
 # -ieee=full enables all IEEE arithmetic facilities
 #          including non-stop arithmetic.
 
-OPTS0    = -u -V -dcfuns -dusty -ieee=full
-MODLIB   = -I./../lapack95_modules
+OPTS0    = %%FFLAGS%% #-u -V -dcfuns -dusty -ieee=full
+MODLIB   = -I./../lapack95_modules -I%%PREFIX%%/lib/lapack95_modules
 OPTS1    = -c $(OPTS0)
 OPTS3    = $(OPTS1) $(MODLIB)
 OPTL     = -o 
 OPTLIB   =
 
-LAPACK_PATH = /usr/local/lib/LAPACK3/
+LAPACK_PATH = -L%%LOCALBASE%%/lib -L%%PREFIX%%/lib
 
-LAPACK95 = ../lapack95.a
-LAPACK77 = $(LAPACK_PATH)/lapack.a
-TMG77    = $(LAPACK_PATH)/tmglib.a
-BLAS     = $(LAPACK_PATH)/blas.a
+LAPACK95 = -llapack95
+LAPACK77 = %%LAPACK%%
+TMG77    = -ltmglib
+BLAS     = %%BLAS%%
 
-LIBS     = $(LAPACK95) $(TMG77) $(LAPACK77) $(BLAS)
+LIBS     = $(LAPACK_PATH) $(LAPACK95) $(LAPACK77) $(TMG77) $(BLAS)
 SUF      = f90
 
 XX = 'rm' -f $@; \
         'rm' -f $@.res; \
 	$(FC) $(OPTS0) -o $@ $(MODLIB) $@.$(SUF) $(OPTLIB) $(LIBS); \
-        $@ < $@.dat > $@.res; \
+        ./$@ < $@.dat > $@.res; \
         'rm' -f $@
 
 YY = $(FC) $(OPTS0) -o $@ $(MODLIB) $@.$(SUF) $(OPTLIB) $(LIBS)
