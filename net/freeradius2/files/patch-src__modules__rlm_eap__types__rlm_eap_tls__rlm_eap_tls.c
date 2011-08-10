--- ./src/modules/rlm_eap/types/rlm_eap_tls/rlm_eap_tls.c.orig	2011-06-20 10:57:14.000000000 -0400
+++ ./src/modules/rlm_eap/types/rlm_eap_tls/rlm_eap_tls.c	2011-08-10 07:03:40.000000000 -0400
@@ -277,6 +277,10 @@
  * This function sends a OCSP request to a defined OCSP responder
  * and checks the OCSP response for correctness.
  */
+
+/* Maximum leeway in validity period: default 5 minutes */
+#define MAX_VALIDITY_PERIOD     (5 * 60)
+
 static int ocsp_check(X509_STORE *store, X509 *issuer_cert, X509 *client_cert,
 		      EAP_TLS_CONF *conf)
 {
@@ -288,9 +292,12 @@
 	char *port = NULL;
 	char *path = NULL;
 	int use_ssl = -1;
-	BIO *cbio;
-	int ocsp_ok;
-	int status;
+	long nsec = MAX_VALIDITY_PERIOD, maxage = -1;
+	BIO *cbio, *bio_out;
+	int ocsp_ok = 0;
+	int status ;
+	ASN1_GENERALIZEDTIME *rev, *thisupd, *nextupd;
+	int reason;
 
 	/* 
 	 * Create OCSP Request 
@@ -299,7 +306,7 @@
 	req = OCSP_REQUEST_new();
 	OCSP_request_add0_id(req, certid);
 	OCSP_request_add1_nonce(req, NULL, 8);
-
+	
 	/* 
 	 * Send OCSP Request and get OCSP Response
 	 */
@@ -316,6 +323,9 @@
 
 	/* Setup BIO socket to OCSP responder */
 	cbio = BIO_new_connect(host);
+
+	bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);
+
 	BIO_set_conn_port(cbio, port);
 	BIO_do_connect(cbio);
 
@@ -323,30 +333,60 @@
 	resp = OCSP_sendreq_bio(cbio, path, req);
 	if(resp==0) {
 		radlog(L_ERR, "Error: Couldn't get OCSP response");
-		ocsp_ok = 0;
 		goto ocsp_end;
 	}
 
-	/* Verify OCSP response */
+	/* Verify OCSP response status */
 	status = OCSP_response_status(resp);
+	DEBUG2("[ocsp] --> Response status: %s",OCSP_response_status_str(status));
 	if(status != OCSP_RESPONSE_STATUS_SUCCESSFUL) {
 		radlog(L_ERR, "Error: OCSP response status: %s", OCSP_response_status_str(status));
-		ocsp_ok = 0;
 		goto ocsp_end;
 	}
 	bresp = OCSP_response_get1_basic(resp);
 	if(OCSP_check_nonce(req, bresp)!=1) {
 		radlog(L_ERR, "Error: OCSP response has wrong nonce value");
-		ocsp_ok = 0;
 		goto ocsp_end;
 	}
 	if(OCSP_basic_verify(bresp, NULL, store, 0)!=1){
 		radlog(L_ERR, "Error: Couldn't verify OCSP basic response");
-		ocsp_ok = 0;
 		goto ocsp_end;
 	}
-	
-	ocsp_ok = 1; 
+	/*	Verify OCSP cert status */
+	if(!OCSP_resp_find_status(bresp, certid, &status, &reason,
+				                      &rev, &thisupd, &nextupd)) {
+		radlog(L_ERR, "ERROR: No Status found.\n");
+		goto ocsp_end;
+	}
+
+	if (!OCSP_check_validity(thisupd, nextupd, nsec, maxage)) {
+		BIO_puts(bio_out, "WARNING: Status times invalid.\n");
+		ERR_print_errors(bio_out);
+		goto ocsp_end;
+	}
+	BIO_puts(bio_out, "\tThis Update: ");
+        ASN1_GENERALIZEDTIME_print(bio_out, thisupd);
+        BIO_puts(bio_out, "\n");
+	BIO_puts(bio_out, "\tNext Update: ");
+        ASN1_GENERALIZEDTIME_print(bio_out, nextupd);
+        BIO_puts(bio_out, "\n");
+
+	switch (status) {
+	case V_OCSP_CERTSTATUS_GOOD:
+		DEBUG2("[oscp] --> Cert status: good");
+		ocsp_ok = 1; 
+		break;
+
+	default:
+		/* REVOKED / UNKNOWN */
+		DEBUG2("[ocsp] --> Cert status: %s",OCSP_cert_status_str(status));
+                if (reason != -1)
+			DEBUG2("[ocsp] --> Reason: %s", OCSP_crl_reason_str(reason));
+                BIO_puts(bio_out, "\tRevocation Time: ");
+                ASN1_GENERALIZEDTIME_print(bio_out, rev);
+                BIO_puts(bio_out, "\n"); 
+		break;
+	}
 
 ocsp_end:
 	/* Free OCSP Stuff */
@@ -1170,7 +1210,7 @@
 		  return -1;
 		}
 	}
-#endif HAVE_OPENSSL_OCSP_H
+#endif /*HAVE_OPENSSL_OCSP_H*/
 
 	if (load_dh_params(inst->ctx, conf->dh_file) < 0) {
 		eaptls_detach(inst);
