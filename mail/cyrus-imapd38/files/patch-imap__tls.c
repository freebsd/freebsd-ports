--- imap/tls.c.orig	2024-03-13 02:47:44 UTC
+++ imap/tls.c
@@ -257,7 +257,11 @@ static DH *get_dh1024(void)
     dh = DH_new();
     if (!dh) return NULL;
 
+#if defined(LIBRESSL_VERSION_NUMBER)
+    p = BN_get_rfc2409_prime_1024(NULL);
+#else
     p = get_rfc2409_prime_1024(NULL);
+#endif
     BN_dec2bn(&g, "2");
 
     if (DH_set0_pqg(dh, p, NULL, g))
