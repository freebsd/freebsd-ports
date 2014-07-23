--- lib/plugins/quorum/quorumd.c.orig
+++ lib/plugins/quorum/quorumd.c
@@ -353,15 +353,28 @@
 	unsigned int cert_list_size;
 	const gnutls_datum *cert_list;
	int ret;
+	int status;
 	gnutls_x509_crt cert;
 
-	ret = gnutls_certificate_verify_peers (session);
+	ret = gnutls_certificate_verify_peers2 (session, &status);
 
 	if (ret < 0)
 	{
 		printf("gnutls_certificate_verify_peers2 returns error.\n");
 		return -1;
 	}
+	if (status & GNUTLS_CERT_INVALID) {
+		printf("The certificate is not trusted.\n");
+		return -1;
+	}
+	if (status & GNUTLS_CERT_SIGNER_NOT_FOUND) {
+		printf("The certificate hasn't got a known issuer.\n");
+		return -1;
+	}
+	if (status & GNUTLS_CERT_REVOKED) {
+		printf("The certificate has been revoked.\n");
+		return -1;
+	}
 	if (gnutls_certificate_type_get (session) != GNUTLS_CRT_X509) {
 		printf("The certificate is not a x.509 cert\n");
     		return -1;
