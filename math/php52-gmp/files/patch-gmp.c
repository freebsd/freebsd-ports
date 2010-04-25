--- gmp.c.orig	2010-04-21 22:00:31.841602968 +0000
+++ gmp.c	2010-04-21 22:00:46.412804473 +0000
@@ -1396,7 +1396,7 @@
 
 		GMPG(rand_initialized) = 1;
 	}
-	mpz_urandomb(*gmpnum_result, GMPG(rand_state), GMP_ABS (limiter) * __GMP_BITS_PER_MP_LIMB);
+	mpz_urandomb(*gmpnum_result, GMPG(rand_state), GMP_ABS (limiter) * GMP_LIMB_BITS);
 
 	ZEND_REGISTER_RESOURCE(return_value, gmpnum_result, le_gmp);
 }
