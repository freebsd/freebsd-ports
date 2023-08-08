--- src/libm-tester/testerutil.h.orig	2021-04-05 11:53:56 UTC
+++ src/libm-tester/testerutil.h
@@ -90,7 +90,5 @@ int cmpDenormsp(float x, mpfr_t fry);
 double countULPsp(float d, mpfr_t c);
 double countULP2sp(float d, mpfr_t c);
 
-void mpfr_sinpi(mpfr_t ret, mpfr_t arg, mpfr_rnd_t rnd);
-void mpfr_cospi(mpfr_t ret, mpfr_t arg, mpfr_rnd_t rnd);
 void mpfr_lgamma_nosign(mpfr_t ret, mpfr_t arg, mpfr_rnd_t rnd);
 #endif
