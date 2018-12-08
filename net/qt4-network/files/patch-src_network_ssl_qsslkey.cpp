--- src/network/ssl/qsslkey.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslkey.cpp
@@ -321,8 +321,19 @@ int QSslKey::length() const
 {
     if (d->isNull)
         return -1;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return (d->algorithm == QSsl::Rsa)
            ? q_BN_num_bits(d->rsa->n) : q_BN_num_bits(d->dsa->p);
+#else
+    if (d->algorithm == QSsl::Rsa) {
+        return q_RSA_bits(d->rsa);
+    }else{
+        BIGNUM *p = NULL;
+        q_DSA_get0_pqg(d->dsa, &p, NULL, NULL);
+	return q_BN_num_bits(p);
+    }
+#endif
+
 }
 
 /*!
