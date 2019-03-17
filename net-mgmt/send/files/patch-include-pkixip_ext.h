--- include/pkixip_ext.h.orig	2019-02-27 16:25:45 UTC
+++ include/pkixip_ext.h
@@ -47,14 +47,30 @@ struct pkixip_config {
 	char *certfile;
 };
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 extern int pkixip_aor_cmp(const char * const *, const char * const *);
 extern int pkixip_ipf_cmp(const char * const *, const char * const *);
+#else
+extern int pkixip_aor_cmp(const IPAddressOrRange * const *,
+    const IPAddressOrRange * const *);
+extern int pkixip_ipf_cmp(const IPAddressFamily * const *,
+    const IPAddressFamily * const *);
+#endif
 
 extern int pkixip_add2stores_cert(X509 *);
 extern int pkixip_add2stores_file(const char *);
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 extern int pkixip_add_store(int *, int (*cmp)(X509_OBJECT **, X509_OBJECT **));
+#else
+extern int pkixip_add_store(int *, int (*cmp)(const X509_OBJECT * const *, const X509_OBJECT * const *));
+#endif
 extern void *pkixip_find_cert(void *, int);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 extern STACK *pkixip_get_mychain(void);
+#else
+extern STACK_OF(X509_OBJECT) *pkixip_get_mychain(void);
+#endif
 extern X509_STORE_CTX *pkixip_get_store_ctx(void);
 extern int pkixip_has_ext(X509 *x);
 extern X509 *pkixip_load_cert(const char *);
