--- src/network/ssl/ssl.c.orig	2025-12-25 11:06:07 UTC
+++ src/network/ssl/ssl.c
@@ -61,9 +61,15 @@ int socket_SSL_ex_data_idx = -1;
 /** Prevent SSL_dup() if the SSL is associated with struct socket.
  * We cannot copy struct socket and it doesn't have a reference count
  * either.  */
+#ifdef LIBRESSL_VERSION_NUMBER
 static int
+socket_SSL_ex_data_dup(CRYPTO_EX_DATA *to, CRYPTO_EX_DATA *from,
+		       WSK from_d, int idx, long argl, void *argp)
+#else
+static int
 socket_SSL_ex_data_dup(CRYPTO_EX_DATA *to, const CRYPTO_EX_DATA *from,
 		       WSK from_d, int idx, long argl, void *argp)
+#endif
 {
 	ELOG
 	/* The documentation of from_d in RSA_get_ex_new_index(3)
