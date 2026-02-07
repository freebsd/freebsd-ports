--- libopendkim/dkim.c.orig	2015-05-12 18:43:09 UTC
+++ libopendkim/dkim.c
@@ -5301,6 +5301,10 @@ dkim_sig_process(DKIM *dkim, DKIM_SIGINFO *sig)
 	size_t diglen = 0;
 #ifdef USE_GNUTLS
 	gnutls_datum_t key;
+#if GNUTLS_VERSION_MAJOR > 2
+	gnutls_digest_algorithm_t hash;
+	gnutls_sign_algorithm_t sign_algo;
+#endif
 #else /* USE_GNUTLS */
 	BIO *key;
 #endif /* USE_GNUTLS */
@@ -5442,7 +5446,20 @@ dkim_sig_process(DKIM *dkim, DKIM_SIGINFO *sig)
 			return DKIM_STAT_OK;
 		}
 
+#if GNUTLS_VERSION_MAJOR < 3
 		rsastat = gnutls_pubkey_verify_hash(rsa->rsa_pubkey, 0,
+#else
+		hash = dkim_libfeature(dkim->dkim_libhandle,
+			    DKIM_FEATURE_SHA256) &&
+			    sig->sig_hashtype == DKIM_HASHTYPE_SHA256
+			    ? GNUTLS_DIG_SHA256 : GNUTLS_DIG_SHA1;
+
+		sign_algo = gnutls_pk_to_sign(GNUTLS_PK_RSA, hash);
+		assert(sign_algo != GNUTLS_SIGN_UNKNOWN);
+
+		rsastat = gnutls_pubkey_verify_hash2(rsa->rsa_pubkey,
+			    sign_algo, 0,
+#endif
 		                                    &rsa->rsa_digest,
 		                                    &rsa->rsa_sig);
 		if (rsastat < 0)
