--- lib/pkcs11h-openssl.c.orig	2022-10-20 14:36:14 UTC
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
 
