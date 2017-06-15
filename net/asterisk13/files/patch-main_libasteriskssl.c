--- main/libasteriskssl.c.orig	2017-04-12 21:07:31 UTC
+++ main/libasteriskssl.c
@@ -74,7 +74,7 @@ static void ssl_lock(int mode, int n, const char *file
 	}
 }
 
-#if !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
+#if !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 int SSL_library_init(void)
 {
 #if defined(AST_DEVMODE)
@@ -129,7 +129,7 @@ void ERR_free_strings(void)
 int ast_ssl_init(void)
 {
 #if defined(HAVE_OPENSSL) && defined(OPENSSL_VERSION_NUMBER) && \
-	OPENSSL_VERSION_NUMBER < 0x10100000L
+	(OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
 	unsigned int i;
 	int (*real_SSL_library_init)(void);
 	void (*real_CRYPTO_set_id_callback)(unsigned long (*)(void));
