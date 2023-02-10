--- src/main/tls.c.orig	2022-10-03 21:51:59 UTC
+++ src/main/tls.c
@@ -3015,7 +3015,14 @@ int cbtls_verify(int ok, X509_STORE_CTX *ctx)
 	 */
 	if (lookup > 1) {
 		if (!my_ok) lookup = 1;
-	} else {
+
+	} else if (lookup == 0) {
+		/*
+		 *	This flag is only set for outbound
+		 *	connections.  And then allows us to remap SSL
+		 *	offset 0 (server) to our offset 1 (also
+		 *	server).
+		 */
 		lookup = (SSL_get_ex_data(ssl, FR_TLS_EX_INDEX_FIX_CERT_ORDER) != NULL);
 	}
 
