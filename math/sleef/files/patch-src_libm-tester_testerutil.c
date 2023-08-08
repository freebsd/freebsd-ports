--- src/libm-tester/testerutil.c.orig	2021-04-05 11:53:56 UTC
+++ src/libm-tester/testerutil.c
@@ -289,32 +289,6 @@ double countULP2sp(float d, mpfr_t c0) {
 
 //
 
-void mpfr_sinpi(mpfr_t ret, mpfr_t arg, mpfr_rnd_t rnd) {
-  mpfr_t frpi, frd;
-  mpfr_inits(frpi, frd, NULL);
-
-  mpfr_const_pi(frpi, GMP_RNDN);
-  mpfr_set_d(frd, 1.0, GMP_RNDN);
-  mpfr_mul(frpi, frpi, frd, GMP_RNDN);
-  mpfr_mul(frd, frpi, arg, GMP_RNDN);
-  mpfr_sin(ret, frd, GMP_RNDN);
-
-  mpfr_clears(frpi, frd, NULL);
-}
-
-void mpfr_cospi(mpfr_t ret, mpfr_t arg, mpfr_rnd_t rnd) {
-  mpfr_t frpi, frd;
-  mpfr_inits(frpi, frd, NULL);
-
-  mpfr_const_pi(frpi, GMP_RNDN);
-  mpfr_set_d(frd, 1.0, GMP_RNDN);
-  mpfr_mul(frpi, frpi, frd, GMP_RNDN);
-  mpfr_mul(frd, frpi, arg, GMP_RNDN);
-  mpfr_cos(ret, frd, GMP_RNDN);
-
-  mpfr_clears(frpi, frd, NULL);
-}
-
 void mpfr_lgamma_nosign(mpfr_t ret, mpfr_t arg, mpfr_rnd_t rnd) {
   int s;
   mpfr_lgamma(ret, &s, arg, rnd);
