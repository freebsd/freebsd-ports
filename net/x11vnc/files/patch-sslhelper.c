--- src/sslhelper.c.orig	2019-01-05 13:22:11 UTC
+++ src/sslhelper.c
@@ -732,8 +732,10 @@ static void ssl_xfer(int csock, int s_in, int s_out, i
 #include <openssl/rand.h>
 
 static SSL_CTX *ctx = NULL;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 static RSA *rsa_512 = NULL;
 static RSA *rsa_1024 = NULL;
+#endif
 static SSL *ssl = NULL;
 static X509_STORE *revocation_store = NULL;
 
@@ -1063,8 +1065,9 @@ void openssl_init(int isclient) {
 		sslerrexit();
 	}
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	ds = dnow();
-	rsa_512 = RSA_generate_key(512, RSA_F4, NULL, NULL);
+	rsa_512 = RSA_generate_key_ex(512, RSA_F4, NULL, NULL);
 	if (rsa_512 == NULL) {
 		rfbLog("openssl_init: RSA_generate_key(512) failed.\n");	
 		sslerrexit();
@@ -1087,6 +1090,7 @@ void openssl_init(int isclient) {
 		rfbLog("openssl_init: SSL_CTX_set_tmp_rsa(1024) failed.\n");	
 		sslerrexit();
 	}
+#endif
 
 	mode = 0;
 	mode |= SSL_MODE_ENABLE_PARTIAL_WRITE;
