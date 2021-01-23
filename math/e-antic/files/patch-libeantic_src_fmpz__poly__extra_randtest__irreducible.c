--- libeantic/src/fmpz_poly_extra/randtest_irreducible.c.orig	2021-01-21 20:23:35 UTC
+++ libeantic/src/fmpz_poly_extra/randtest_irreducible.c
@@ -18,14 +18,25 @@ void fmpz_poly_randtest_irreducible(fmpz_poly_t p, fli
     slong i;
     fmpz_t c;
     fmpz_mod_poly_t q;
+#if __FLINT_RELEASE >= 20700
+    fmpz_mod_ctx_t ctx;
+#endif
 
     fmpz_init(c);
 
     fmpz_randprime(c, state, bits, 0);
+#if __FLINT_RELEASE >= 20700
+    fmpz_mod_ctx_init(ctx, c);
+    fmpz_mod_poly_init(q, ctx);
+    fmpz_mod_poly_randtest_irreducible(q, state, len, ctx);
+
+    fmpz_mod_poly_get_fmpz_poly(p, q, ctx);
+#else
     fmpz_mod_poly_init(q, c);
     fmpz_mod_poly_randtest_irreducible(q, state, len);
 
     fmpz_mod_poly_get_fmpz_poly(p, q);
+#endif
 
     /* After lifting, the coefficients belong to {0, ..., c-1}. We now  */
     /* randomly subtract c so that some of them become negative.        */
@@ -38,6 +49,11 @@ void fmpz_poly_randtest_irreducible(fmpz_poly_t p, fli
                 c);
     }
 
+#if __FLINT_RELEASE >= 20700
+    fmpz_mod_poly_clear(q, ctx);
+    fmpz_mod_ctx_clear(ctx);
+#else
     fmpz_mod_poly_clear(q);
+#endif
     fmpz_clear(c);
 }
