--- membership/quorumd/quorumdtest.c.orig
+++ membership/quorumd/quorumdtest.c
@@ -162,16 +162,16 @@
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
-/*	
 	if (status & GNUTLS_CERT_INVALID) {
 		printf("The certificate is not trusted.\n");
 		return -1;
@@ -184,7 +184,6 @@
 		printf("The certificate has been revoked.\n");
 		return -1;
 	}
-*/	
 	if (gnutls_certificate_type_get (session) != GNUTLS_CRT_X509) {
 		printf("The certificate is not a x.509 cert\n");
     		return -1;
