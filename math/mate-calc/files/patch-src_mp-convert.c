--- src/mp-convert.c.orig	2021-10-09 20:03:44 UTC
+++ src/mp-convert.c
@@ -40,7 +40,7 @@ mp_set_from_integer(long x, MPNumber *z)
 
 
 void
-mp_set_from_unsigned_integer(ulong x, MPNumber *z)
+mp_set_from_unsigned_integer(unsigned long x, MPNumber *z)
 {
     mpc_set_ui(z->num, x, MPC_RNDNN);
 }
@@ -95,7 +95,7 @@ mp_to_integer(const MPNumber *x)
 }
 
 
-ulong
+unsigned long
 mp_to_unsigned_integer(const MPNumber *x)
 {
     return mpfr_get_ui(mpc_realref(x->num), MPFR_RNDN);
