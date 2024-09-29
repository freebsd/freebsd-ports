--- libpurple/plugins/ssl/ssl-nss.c
+++ libpurple/plugins/ssl/ssl-nss.c
@@ -282,39 +282,32 @@ x509_import_from_nss(CERTCertificate* ce
 static GList *
 ssl_nss_get_peer_certificates(PRFileDesc *socket, PurpleSslConnection * gsc)
 {
+	CERTCertList *peerChain;
+	CERTCertListNode *cursor;
 	CERTCertificate *curcert;
-	CERTCertificate *issuerCert;
 	PurpleCertificate * newcrt;

 	/* List of Certificate instances to return */
 	GList * peer_certs = NULL;
-	int count;
-	int64 now = PR_Now();

-	curcert = SSL_PeerCertificate(socket);
-	if (curcert == NULL) {
-		purple_debug_error("nss", "could not DupCertificate\n");
+	peerChain = SSL_PeerCertificateChain(socket);
+	if (peerChain == NULL) {
+		purple_debug_error("nss", "no peer certificates\n");
 		return NULL;
 	}

-	for (count = 0 ; count < CERT_MAX_CERT_CHAIN ; count++) {
+	for (cursor = CERT_LIST_HEAD(peerChain); !CERT_LIST_END(cursor, peerChain); cursor = CERT_LIST_NEXT(cursor)) {
+		curcert = cursor->cert;
+		if (!curcert) {
+			purple_debug_error("nss", "cursor->cert == NULL\n");
+			break;
+		}
 		purple_debug_info("nss", "subject=%s issuer=%s\n", curcert->subjectName,
 						  curcert->issuerName  ? curcert->issuerName : "(null)");
 		newcrt = x509_import_from_nss(curcert);
 		peer_certs = g_list_append(peer_certs, newcrt);
-
-		if (curcert->isRoot) {
-			break;
-		}
-		issuerCert = CERT_FindCertIssuer(curcert, now, certUsageSSLServer);
-		if (!issuerCert) {
-			purple_debug_error("nss", "partial certificate chain\n");
-			break;
-		}
-		CERT_DestroyCertificate(curcert);
-		curcert = issuerCert;
 	}
-	CERT_DestroyCertificate(curcert);
+	CERT_DestroyCertList(peerChain);

 	return peer_certs;
 }
