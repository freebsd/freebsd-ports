--- membership/quorumd/quorumd.c.orig
+++ membership/quorumd/quorumd.c
@@ -476,17 +476,30 @@
 	unsigned int cert_list_size;
 	const gnutls_datum *cert_list;
	int ret;
+	int status;
 	char dn[MAX_DN_LEN];
 	size_t dn_len = MAX_DN_LEN;
 	gnutls_x509_crt cert;
 
-	ret = gnutls_certificate_verify_peers(session);
+	ret = gnutls_certificate_verify_peers2(session, &status);
 
 	if (ret < 0)
 	{
 		quorum_debug(LOG_DEBUG,"gnutls_certificate_verify_peers2 returns error");
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
 		quorum_debug(LOG_DEBUG,"The certificate is not a x.509 cert");
     		return -1;
