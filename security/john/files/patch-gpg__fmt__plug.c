--- gpg_fmt_plug.c.orig	2014-12-18 07:59:02 UTC
+++ gpg_fmt_plug.c
@@ -930,8 +930,12 @@ static int check_dsa_secret_key(DSA *dsa)
 {
 	int error;
 	int rc = -1;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+	const BIGNUM *p, *q, *g, *pub_key, *priv_key;
+#endif
 	BIGNUM *res = BN_new();
 	BN_CTX *ctx = BN_CTX_new();
+
 	if (!res) {
 		fprintf(stderr, "failed to allocate result BN in check_dsa_secret_key()\n");
 		exit(-1);
@@ -941,23 +945,35 @@ static int check_dsa_secret_key(DSA *dsa)
 		exit(-1);
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+	DSA_get0_pqg(dsa, &p, &q, &g);
+	DSA_get0_key(dsa, &pub_key, &priv_key);
+	error = BN_mod_exp(res, g, priv_key, p, ctx);
+#else
 	error = BN_mod_exp(res, dsa->g, dsa->priv_key, dsa->p, ctx);
+#endif
+
 	if ( error == 0 ) {
 		goto freestuff;
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+	rc = BN_cmp(res, pub_key);
+#else
 	rc = BN_cmp(res, dsa->pub_key);
+#endif
 
 freestuff:
 
 	BN_CTX_free(ctx);
 	BN_free(res);
+#if OPENSSL_VERSION_NUMBER < 0x10100000
 	BN_free(dsa->g);
 	BN_free(dsa->q);
 	BN_free(dsa->p);
 	BN_free(dsa->pub_key);
 	BN_free(dsa->priv_key);
-
+#endif
 	return rc;
 }
 
@@ -1212,9 +1228,7 @@ static int check(unsigned char *keydata, int ks)
 			return 0;
 		if (blen < cur_salt->datalen && ((b = BN_bin2bn(out + 2, blen, NULL)) != NULL)) {
 			char *str = BN_bn2hex(b);
-			DSA dsa;
-			ElGamal_secret_key elg;
-			RSA_secret_key rsa;
+
 			if (strlen(str) != blen * 2) { /* verifier 2 */
 				OPENSSL_free(str);
 				return 0;
@@ -1222,6 +1236,28 @@ static int check(unsigned char *keydata, int ks)
 			OPENSSL_free(str);
 
 			if (cur_salt->pk_algorithm == 17) { /* DSA check */
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+				DSA *dsa = DSA_new();
+				BIGNUM *p, *q, *g, *pub_key, *priv_key;
+
+				p = BN_bin2bn(cur_salt->p, cur_salt->pl, NULL);
+				// puts(BN_bn2hex(dsa.p));
+				q = BN_bin2bn(cur_salt->q, cur_salt->ql, NULL);
+				// puts(BN_bn2hex(dsa.q));
+				g = BN_bin2bn(cur_salt->g, cur_salt->gl, NULL);
+				// puts(BN_bn2hex(dsa.g));
+				priv_key = b;
+				pub_key = BN_bin2bn(cur_salt->y, cur_salt->yl, NULL);
+
+				DSA_set0_pqg(dsa, p, q, g);
+				DSA_set0_key(dsa, pub_key, priv_key);
+
+				// puts(BN_bn2hex(dsa.pub_key));
+				ret = check_dsa_secret_key(dsa); /* verifier 3 */
+				DSA_free(dsa);
+#else
+				DSA dsa;
+
 				dsa.p = BN_bin2bn(cur_salt->p, cur_salt->pl, NULL);
 				// puts(BN_bn2hex(dsa.p));
 				dsa.q = BN_bin2bn(cur_salt->q, cur_salt->ql, NULL);
@@ -1232,10 +1268,13 @@ static int check(unsigned char *keydata, int ks)
 				dsa.pub_key = BN_bin2bn(cur_salt->y, cur_salt->yl, NULL);
 				// puts(BN_bn2hex(dsa.pub_key));
 				ret = check_dsa_secret_key(&dsa); /* verifier 3 */
+#endif
 				if (ret != 0)
 					return 0;
 			}
 			if (cur_salt->pk_algorithm == 16 || cur_salt->pk_algorithm == 20) { /* ElGamal check */
+				ElGamal_secret_key elg;
+
 				elg.p = BN_bin2bn(cur_salt->p, cur_salt->pl, NULL);
 				// puts(BN_bn2hex(elg.p));
 				elg.g = BN_bin2bn(cur_salt->g, cur_salt->gl, NULL);
@@ -1249,8 +1288,10 @@ static int check(unsigned char *keydata, int ks)
 					return 0;
 			}
 			if (cur_salt->pk_algorithm == 1) { /* RSA check */
+				RSA_secret_key rsa;
 				// http://www.ietf.org/rfc/rfc4880.txt
 				int length = 0;
+
 				length += give_multi_precision_integer(out, length, &cur_salt->dl, cur_salt->d);
 				length += give_multi_precision_integer(out, length, &cur_salt->pl, cur_salt->p);
 				length += give_multi_precision_integer(out, length, &cur_salt->ql, cur_salt->q);
