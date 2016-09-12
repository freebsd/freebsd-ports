--- lib/pki_temp.cpp.orig	2015-10-10 12:54:12 UTC
+++ lib/pki_temp.cpp
@@ -363,7 +363,7 @@ BIO *pki_temp::pem(BIO *b, int format)
 	QByteArray ba = toExportData();
         if (!b)
 		b = BIO_new(BIO_s_mem());
-#if OPENSSL_VERSION_NUMBER < 0x10002000L
+#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(LIBRESSL_VERSION_NUMBER)
 	PEM_write_bio(b, PEM_STRING_XCA_TEMPLATE, (char*)"",
 		(unsigned char*)(ba.data()), ba.size());
 #else
