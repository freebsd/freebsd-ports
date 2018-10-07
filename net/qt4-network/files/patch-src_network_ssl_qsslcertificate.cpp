--- src/network/ssl/qsslcertificate.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslcertificate.cpp
@@ -260,8 +260,13 @@ QByteArray QSslCertificate::version() co
 {
     QMutexLocker lock(QMutexPool::globalInstanceGet(d.data()));
     if (d->versionString.isEmpty() && d->x509)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+	d->versionString =
+	    QByteArray::number(qlonglong(q_X509_get_version(d->x509)) + 1);
+#else
         d->versionString =
             QByteArray::number(qlonglong(q_ASN1_INTEGER_get(d->x509->cert_info->version)) + 1);
+#endif
 
     return d->versionString;
 }
@@ -276,7 +281,11 @@ QByteArray QSslCertificate::serialNumber
 {
     QMutexLocker lock(QMutexPool::globalInstanceGet(d.data()));
     if (d->serialNumberString.isEmpty() && d->x509) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+	ASN1_INTEGER *serialNumber = q_X509_get_serialNumber(d->x509);
+#else
         ASN1_INTEGER *serialNumber = d->x509->cert_info->serialNumber;
+#endif
         // if we cannot convert to a long, just output the hexadecimal number
         if (serialNumber->length > 4) {
             QByteArray hexString;
@@ -489,19 +498,37 @@ QSslKey QSslCertificate::publicKey() con
     QSslKey key;
 
     key.d->type = QSsl::PublicKey;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    EVP_PKEY *pkey = q_X509_get_pubkey(d->x509);
+#else
     X509_PUBKEY *xkey = d->x509->cert_info->key;
     EVP_PKEY *pkey = q_X509_PUBKEY_get(xkey);
+#endif
     Q_ASSERT(pkey);
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    int keyType = q_EVP_PKEY_type(q_EVP_PKEY_base_id(pkey));
+
+    if (keyType == EVP_PKEY_RSA) {
+#else
     if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_RSA) {
+#endif
         key.d->rsa = q_EVP_PKEY_get1_RSA(pkey);
         key.d->algorithm = QSsl::Rsa;
         key.d->isNull = false;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    } else if (keyType == EVP_PKEY_DSA) {
+#else
     } else if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_DSA) {
+#endif
         key.d->dsa = q_EVP_PKEY_get1_DSA(pkey);
         key.d->algorithm = QSsl::Dsa;
         key.d->isNull = false;
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    } else if (keyType == EVP_PKEY_DH) {
+#else
     } else if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_DH) {
+#endif
         // DH unsupported
     } else {
         // error?
@@ -698,8 +725,13 @@ QSslCertificate QSslCertificatePrivate::
     if (!x509 || !QSslSocket::supportsSsl())
         return certificate;
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    const ASN1_TIME *nbef = q_X509_get0_notBefore(x509);
+    const ASN1_TIME *naft = q_X509_get0_notAfter(x509);
+#else
     ASN1_TIME *nbef = q_X509_get_notBefore(x509);
     ASN1_TIME *naft = q_X509_get_notAfter(x509);
+#endif
     certificate.d->notValidBefore = q_getTimeFromASN1(nbef);
     certificate.d->notValidAfter = q_getTimeFromASN1(naft);
     certificate.d->null = false;
