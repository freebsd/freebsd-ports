--- src/ssl/bio.h.orig	2017-02-05 21:15:41 UTC
+++ src/ssl/bio.h
@@ -205,7 +205,7 @@ private:
 void
 applyTlsDetailsToSSL(SSL *ssl, Security::TlsDetails::Pointer const &details, Ssl::BumpMode bumpMode);
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
 // OpenSSL v1.0 bio compatibility functions
 inline void *BIO_get_data(BIO *table) { return table->ptr; }
 inline void BIO_set_data(BIO *table, void *data) { table->ptr = data; }
