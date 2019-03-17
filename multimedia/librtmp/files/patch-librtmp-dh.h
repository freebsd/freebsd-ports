--- librtmp/dh.h.orig	2016-02-29 01:15:13 UTC
+++ librtmp/dh.h
@@ -194,7 +194,7 @@ typedef BIGNUM * MP_t;
 
 /* RFC 2631, Section 2.1.5, http://www.ietf.org/rfc/rfc2631.txt */
 static int
-isValidPublicKey(MP_t y, MP_t p, MP_t q)
+isValidPublicKey(const MP_t y, const MP_t p, const MP_t q)
 {
   int ret = TRUE;
   MP_t bn;
@@ -253,20 +253,43 @@ DHInit(int nKeyBits)
   if (!dh)
     goto failed;
 
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   MP_new(dh->g);
 
   if (!dh->g)
     goto failed;
+#else
+  BIGNUM *g;
 
+  MP_new(g);
+  if (g == NULL)
+    goto failed;
+#endif
+
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   MP_gethex(dh->p, P1024, res);	/* prime P1024, see dhgroups.h */
+#else
+  const BIGNUM *p = DH_get0_p(dh);
+
+  MP_gethex(p, P1024, res);	/* prime P1024, see dhgroups.h */
+#endif
   if (!res)
     {
       goto failed;
     }
 
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   MP_set_w(dh->g, 2);	/* base 2 */
+#else
+  MP_set_w(g, 2);	/* base 2 */
+  DH_set0_pqg(dh, p, NULL, g);
+#endif
 
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   dh->length = nKeyBits;
+#else
+  DH_set_length(dh, nKeyBits);
+#endif
   return dh;
 
 failed:
@@ -293,12 +316,20 @@ DHGenerateKey(MDH *dh)
       MP_gethex(q1, Q1024, res);
       assert(res);
 
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
       res = isValidPublicKey(dh->pub_key, dh->p, q1);
+#else
+      res = isValidPublicKey(DH_get0_pub_key(dh), DH_get0_p(dh), q1);
+#endif
       if (!res)
 	{
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
 	  MP_free(dh->pub_key);
 	  MP_free(dh->priv_key);
 	  dh->pub_key = dh->priv_key = 0;
+#else
+          DH_set0_key(dh, NULL, NULL);
+#endif
 	}
 
       MP_free(q1);
@@ -314,15 +345,27 @@ static int
 DHGetPublicKey(MDH *dh, uint8_t *pubkey, size_t nPubkeyLen)
 {
   int len;
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   if (!dh || !dh->pub_key)
+#else
+  if (!dh || !DH_get0_pub_key(dh))
+#endif
     return 0;
 
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   len = MP_bytes(dh->pub_key);
+#else
+  len = MP_bytes(DH_get0_pub_key(dh));
+#endif
   if (len <= 0 || len > (int) nPubkeyLen)
     return 0;
 
   memset(pubkey, 0, nPubkeyLen);
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   MP_setbin(dh->pub_key, pubkey + (nPubkeyLen - len), len);
+#else
+  MP_setbin(DH_get0_pub_key(dh), pubkey + (nPubkeyLen - len), len);
+#endif
   return 1;
 }
 
@@ -364,7 +407,11 @@ DHComputeSharedSecretKey(MDH *dh, uint8_
   MP_gethex(q1, Q1024, len);
   assert(len);
 
+#if !defined(USE_OPENSSL) || defined(LIBRESSL_VERSION_NUMBER) || !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   if (isValidPublicKey(pubkeyBn, dh->p, q1))
+#else
+  if (isValidPublicKey(pubkeyBn, DH_get0_p(dh), q1))
+#endif
     res = MDH_compute_key(secret, nPubkeyLen, pubkeyBn, dh);
   else
     res = -1;
