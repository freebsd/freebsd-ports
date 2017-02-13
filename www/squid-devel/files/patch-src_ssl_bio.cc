--- src/ssl/bio.cc.orig	2017-02-05 21:15:41 UTC
+++ src/ssl/bio.cc
@@ -43,7 +43,7 @@ static int squid_bio_destroy(BIO *data);
 /* SSL callbacks */
 static void squid_ssl_info(const SSL *ssl, int where, int ret);
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
 /// Initialization structure for the BIO table with
 /// Squid-specific methods and BIO method wrappers.
 static BIO_METHOD SquidMethods = {
@@ -65,7 +65,7 @@ static BIO_METHOD *SquidMethods = NULL;
 BIO *
 Ssl::Bio::Create(const int fd, Ssl::Bio::Type type)
 {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     BIO_METHOD *useMethod = &SquidMethods;
 #else
     if (!SquidMethods) {
@@ -562,7 +562,7 @@ Ssl::ServerBio::resumingSession()
 static int
 squid_bio_create(BIO *bi)
 {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     bi->init = 0; // set when we store Bio object and socket fd (BIO_C_SET_FD)
     bi->num = 0;
     bi->flags = 0;
@@ -706,7 +706,7 @@ applyTlsDetailsToSSL(SSL *ssl, Security:
             cbytes[0] = (cipherId >> 8) & 0xFF;
             cbytes[1] = cipherId & 0xFF;
             cbytes[2] = 0;
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
             const SSL_METHOD *method = SSLv23_method();
             const SSL_CIPHER *c = method->get_cipher_by_char(cbytes);
 #else
