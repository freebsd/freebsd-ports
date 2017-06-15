--- content/fetchers/curl.c.orig	2016-11-19 13:37:41 UTC
+++ content/fetchers/curl.c
@@ -128,6 +128,28 @@ static char fetch_error_buffer[CURL_ERRO
 static char fetch_proxy_userpwd[100];
 
 
+/* OpenSSL 1.0.x to 1.1.0 certificate reference counting changed
+ * LibreSSL declares its OpenSSL version as 2.1 but only supports the old way
+ */
+#if (defined(LIBRESSL_VERSION_NUMBER) || (OPENSSL_VERSION_NUMBER < 0x1010000fL))
+static int ns_X509_up_ref(X509 *cert)
+{
+	cert->references++;
+	return 1;
+}
+
+static void ns_X509_free(X509 *cert)
+{
+	cert->references--;
+	if (cert->references == 0) {
+		X509_free(cert);
+	}
+}
+#else
+#define ns_X509_up_ref X509_up_ref
+#define ns_X509_free X509_free
+#endif
+
 /**
  * Initialise a cURL fetcher.
  */
@@ -438,7 +460,7 @@ fetch_curl_verify_callback(int verify_ok
 	 */
 	if (!fetch->cert_data[depth].cert) {
 		fetch->cert_data[depth].cert = X509_STORE_CTX_get_current_cert(x509_ctx);
-		fetch->cert_data[depth].cert->references++;
+		ns_X509_up_ref(fetch->cert_data[depth].cert);
 		fetch->cert_data[depth].err = X509_STORE_CTX_get_error(x509_ctx);
 	}
 
@@ -815,10 +837,7 @@ static void fetch_curl_free(void *vf)
 	}
 
 	for (i = 0; i < MAX_CERTS && f->cert_data[i].cert; i++) {
-		f->cert_data[i].cert->references--;
-		if (f->cert_data[i].cert->references == 0) {
-			X509_free(f->cert_data[i].cert);
-		}
+		ns_X509_free(f->cert_data[i].cert);
 	}
 
 	free(f);
@@ -986,10 +1005,7 @@ curl_start_cert_validate(struct curl_fet
 					      X509_get_pubkey(certs[depth].cert));
 
 		/* and clean up */
-		certs[depth].cert->references--;
-		if (certs[depth].cert->references == 0) {
-			X509_free(certs[depth].cert);
-		}
+		ns_X509_free(certs[depth].cert);
 	}
 
 	msg.type = FETCH_CERT_ERR;
