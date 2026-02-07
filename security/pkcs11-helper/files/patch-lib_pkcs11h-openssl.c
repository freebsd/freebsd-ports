--- lib/pkcs11h-openssl.c.orig	2024-09-04 08:44:23 UTC
+++ lib/pkcs11h-openssl.c
@@ -334,16 +334,26 @@ static struct {
 #endif
 } __openssl_methods;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100001L
+#if OPENSSL_VERSION_NUMBER < 0x10100001L || defined(LIBRESSL_VERSION_NUMBER)
 static
 int
 __pkcs11h_openssl_ex_data_dup (
 	CRYPTO_EX_DATA *to,
 	CRYPTO_EX_DATA *from,
-	void **from_d,
+	void *from_d,
 	int idx,
 	long argl,
 	void *argp
+) {
+#elif OPENSSL_VERSION_NUMBER < 0x30000000L
+int
+__pkcs11h_openssl_ex_data_dup (
+        CRYPTO_EX_DATA *to,
+        const CRYPTO_EX_DATA *from,
+        void *from_d,
+        int idx,
+        long argl,
+        void *argp
 ) {
 #else
 int
