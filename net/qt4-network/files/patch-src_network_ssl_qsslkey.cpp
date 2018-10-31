--- src/network/ssl/qsslkey.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslkey.cpp
@@ -321,8 +321,12 @@ int QSslKey::length() const
 {
     if (d->isNull)
         return -1;
-    return (d->algorithm == QSsl::Rsa)
-           ? q_BN_num_bits(d->rsa->n) : q_BN_num_bits(d->dsa->p);
+    return (d->algorithm == QSsl::Rsa) ?
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        q_BN_num_bits(RSA_get0_n(d->rsa)) : q_BN_num_bits(DSA_get0_p(d->dsa));
+#else
+        q_BN_num_bits(d->rsa->n) : q_BN_num_bits(d->dsa->p);
+#endif
 }
 
 /*!
