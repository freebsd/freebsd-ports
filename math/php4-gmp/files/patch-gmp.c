--- gmp.c.orig	2010-04-13 14:04:55.000000000 +0200
+++ gmp.c	2010-04-13 14:05:23.000000000 +0200
@@ -1159,7 +1159,7 @@
 
 		GMPG(rand_initialized) = 1;
 	}
-	mpz_urandomb(*gmpnum_result, GMPG(rand_state), GMP_ABS (limiter) * __GMP_BITS_PER_MP_LIMB);
+	mpz_urandomb(*gmpnum_result, GMPG(rand_state), GMP_ABS (limiter) * GMP_LIMB_BITS);
 
 	ZEND_REGISTER_RESOURCE(return_value, gmpnum_result, le_gmp);
 }
