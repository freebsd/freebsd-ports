--- src/network/ssl/qsslcertificate_openssl.cpp.orig	2022-06-22 10:58:13 UTC
+++ src/network/ssl/qsslcertificate_openssl.cpp
@@ -691,7 +691,7 @@ static QMultiMap<QByteArray, QString> _q_mapFromX509Na
         unsigned char *data = nullptr;
         int size = q_ASN1_STRING_to_UTF8(&data, q_X509_NAME_ENTRY_get_data(e));
         info.insert(name, QString::fromUtf8((char*)data, size));
-#if QT_CONFIG(opensslv11)
+#if QT_CONFIG(opensslv11) && !defined(LIBRESSL_VERSION_NUMBER)
         q_CRYPTO_free(data, nullptr, 0);
 #else
         q_CRYPTO_free(data);
