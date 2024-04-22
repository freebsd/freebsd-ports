--- lib/pkcs11h-openssl.c.orig	2022-04-07 17:01:01 UTC
+++ lib/pkcs11h-openssl.c
@@ -235,9 +235,13 @@ DSA_meth_free (DSA_METHOD *meth)
 static int
 DSA_meth_set1_name (DSA_METHOD *meth, const char *name)
 {
+#if (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x30500000L)
+	return 0;
+#else
 	CK_RV rv;
 	rv = _pkcs11h_mem_strdup ((void *)&meth->name, name);
 	return rv == CKR_OK ? 1 : 0;
+#endif
 }
 #endif
 
@@ -330,7 +334,7 @@ static struct {
 #endif
 } __openssl_methods;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100001L
+#if OPENSSL_VERSION_NUMBER < 0x10100001L || defined(LIBRESSL_VERSION_NUMBER)
 static
 int
 __pkcs11h_openssl_ex_data_dup (
@@ -341,12 +345,22 @@ __pkcs11h_openssl_ex_data_dup (
 	long argl,
 	void *argp
 ) {
-#else
+#elif OPENSSL_VERSION_NUMBER < 0x30000000L
 int
 __pkcs11h_openssl_ex_data_dup (
 	CRYPTO_EX_DATA *to,
 	const CRYPTO_EX_DATA *from,
 	void *from_d,
+	int idx,
+	long argl,
+	void *argp
+) {
+#else
+int
+__pkcs11h_openssl_ex_data_dup (
+	CRYPTO_EX_DATA *to,
+	const CRYPTO_EX_DATA *from,
+	void **from_d,
 	int idx,
 	long argl,
 	void *argp
