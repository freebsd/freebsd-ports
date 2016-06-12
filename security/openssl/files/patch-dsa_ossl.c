
Fix DSA, preserve BN_FLG_CONSTTIME

Operations in the DSA signing algorithm should run in constant time in
order to avoid side channel attacks. A flaw in the OpenSSL DSA
implementation means that a non-constant time codepath is followed for
certain operations. This has been demonstrated through a cache-timing
attack to be sufficient for an attacker to recover the private DSA key.

CVE-2016-2178

--- crypto/dsa/dsa_ossl.c.orig	2016-05-03 15:44:42.000000000 +0200
+++ crypto/dsa/dsa_ossl.c	2016-06-12 22:57:49.000000000 +0200
@@ -248,9 +248,6 @@
         if (!BN_rand_range(&k, dsa->q))
             goto err;
     while (BN_is_zero(&k)) ;
-    if ((dsa->flags & DSA_FLAG_NO_EXP_CONSTTIME) == 0) {
-        BN_set_flags(&k, BN_FLG_CONSTTIME);
-    }
 
     if (dsa->flags & DSA_FLAG_CACHE_MONT_P) {
         if (!BN_MONT_CTX_set_locked(&dsa->method_mont_p,
@@ -282,6 +279,11 @@
     } else {
         K = &k;
     }
+
+    if ((dsa->flags & DSA_FLAG_NO_EXP_CONSTTIME) == 0) {
+        BN_set_flags(&k, BN_FLG_CONSTTIME);
+    }
+
     DSA_BN_MOD_EXP(goto err, dsa, r, dsa->g, K, dsa->p, ctx,
                    dsa->method_mont_p);
     if (!BN_mod(r, r, dsa->q, ctx))
