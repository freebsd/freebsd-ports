--- src/network/ssl/qsslkey.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslkey.cpp
@@ -321,8 +321,13 @@ int QSslKey::length() const
 {
     if (d->isNull)
         return -1;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+    return (d->algorithm == QSsl::Rsa)
+	   ? q_RSA_bits(d->rsa) : q_DSA_bits(d->dsa);
+#else
     return (d->algorithm == QSsl::Rsa)
            ? q_BN_num_bits(d->rsa->n) : q_BN_num_bits(d->dsa->p);
+#endif
 }
 
 /*!
