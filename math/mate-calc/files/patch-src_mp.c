--- src/mp.c.orig	2021-08-04 12:19:50 UTC
+++ src/mp.c
@@ -59,7 +59,7 @@ mp_new(void)
 }
 
 MPNumber
-mp_new_from_unsigned_integer(ulong x)
+mp_new_from_unsigned_integer(unsigned long x)
 {
     MPNumber z;
     mpc_init2(z.num, PRECISION);
@@ -413,16 +413,16 @@ mp_reciprocal(const MPNumber *x, MPNumber *z)
 void
 mp_root(const MPNumber *x, long n, MPNumber *z)
 {
-    ulong p;
+    unsigned long p;
 
     if (n < 0)
     {
         mpc_ui_div(z->num, 1, x->num, MPC_RNDNN);
 
         if (n == LONG_MIN)
-            p = (ulong) LONG_MAX + 1;
+            p = (unsigned long) LONG_MAX + 1;
         else
-            p = (ulong) -n;
+            p = (unsigned long) -n;
     }
     else if (n > 0)
     {
@@ -490,7 +490,7 @@ mp_factorial(const MPNumber *x, MPNumber *z)
     else
     {
         /* Convert to integer - if couldn't be converted then the factorial would be too big anyway */
-        ulong value = mp_to_unsigned_integer(x);
+        unsigned long value = mp_to_unsigned_integer(x);
         mpfr_fac_ui(mpc_realref(z->num), value, MPFR_RNDN);
         mpfr_set_zero(mpc_imagref(z->num), MPFR_RNDN);
     }
@@ -656,11 +656,11 @@ mp_zeta(const MPNumber *x, MPNumber *z)
  * Returns TRUE if @n is probable prime and FALSE otherwise.
  */
 static bool
-mp_is_pprime(MPNumber *n, ulong rounds)
+mp_is_pprime(MPNumber *n, unsigned long rounds)
 {
     MPNumber tmp = mp_new();
     MPNumber two = mp_new_from_unsigned_integer(2);
-    ulong l = 0;
+    unsigned long l = 0;
     bool is_pprime = TRUE;
 
     /* Write t := n-1 = 2^l * q with q odd */
@@ -680,7 +680,7 @@ mp_is_pprime(MPNumber *n, ulong rounds)
     MPNumber a = mp_new_from_unsigned_integer(1);
     MPNumber b = mp_new();
 
-    for (ulong i = 1; (i < mp_to_integer(&t)) && (i <= rounds+1); i++)
+    for (unsigned long i = 1; (i < mp_to_integer(&t)) && (i <= rounds+1); i++)
     {
         mp_add_integer(&a, 1, &a);
         mp_modular_exponentiation(&a, &q, n, &b);
@@ -752,7 +752,7 @@ mp_gcd (const MPNumber *a, const MPNumber *b, MPNumber
  * Returns FALSE otherwise.
  */
 static bool
-mp_pollard_rho (const MPNumber *n, ulong i, MPNumber *z)
+mp_pollard_rho (const MPNumber *n, unsigned long i, MPNumber *z)
 {
     MPNumber one = mp_new_from_unsigned_integer(1);
     MPNumber two = mp_new_from_unsigned_integer(2);
@@ -809,7 +809,7 @@ static void
 find_big_prime_factor (const MPNumber *n, MPNumber *z)
 {
     MPNumber tmp = mp_new();
-    ulong i = 2;
+    unsigned long i = 2;
 
     while (TRUE)
     {
