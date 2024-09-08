--- src/pki_x509.c	2024-08-14 14:45:55 +0000
+++ ../libpki-0.9.2-patched/src/pki_x509.c	2024-08-14 15:08:49 +0000
@@ -33,22 +33,75 @@
 	{ NULL, -1 }
 };
 
-PKI_TBS_ASN1 * __datatype_get_asn1_ref(PKI_DATATYPE   type, 
-                                       const void   * v) {
+const ASN1_ITEM * _get_ossl_item(PKI_DATATYPE type) {
+
+		const ASN1_ITEM * it = NULL;
+
+	// Gets the ASN1_ITEM * needed to get the tbSigned
+	switch (type) {
+
+		case PKI_DATATYPE_X509_CERT : {
+			it = ASN1_ITEM_rptr(X509_CINF);
+		} break;
+
+		case PKI_DATATYPE_X509_CRL : {
+			it = ASN1_ITEM_rptr(X509_CRL_INFO);
+		} break;
+
+		case PKI_DATATYPE_X509_REQ : {
+			it = ASN1_ITEM_rptr(X509_REQ_INFO);
+		} break;
+
+		case PKI_DATATYPE_X509_OCSP_REQ : {
+			it = ASN1_ITEM_rptr(OCSP_REQINFO);
+		} break;
+
+		case PKI_DATATYPE_X509_OCSP_RESP : {
+			it = ASN1_ITEM_rptr(OCSP_RESPDATA);
+		} break;
+
+		case PKI_DATATYPE_X509_PRQP_REQ : {
+			it = ASN1_ITEM_rptr(PKI_PRQP_REQ);
+		} break;
+
+		case PKI_DATATYPE_X509_PRQP_RESP : {
+			it = ASN1_ITEM_rptr(PKI_PRQP_RESP);
+		} break;
+
+		case PKI_DATATYPE_X509_CMS : {
+			it = ASN1_ITEM_rptr(CMS_ContentInfo);
+		} break;
+
+		case PKI_DATATYPE_X509_KEYPAIR: {
+			it = NULL;
+		} break;
+
+		default: {
+			PKI_DEBUG("Datatype Not Supported (Type: %d)", type);
+			return NULL;
+		}
+	}
+
+	// Return the Pointer
+	return it;
+
+}
+
+PKI_TBS_ASN1 * __datatype_get_asn1_ref(PKI_DATATYPE   type,
+				       const void   * v) {
 
 	PKI_TBS_ASN1 * ret = NULL;
 	const ASN1_ITEM * it = NULL;
 	const void * p = NULL;
 
+	if ((it = _get_ossl_item(type)) == NULL) {
+		return NULL;
+	}
+
 	// Gets the ASN1_ITEM * needed to get the tbSigned
 	switch (type) {
 
 		case PKI_DATATYPE_X509_CERT : {
-#if OPENSSL_VERSION_NUMBER >= 0x30000000L
-		        it = (ASN1_ITEM *) X509_CINF_it;
-#else
-			it = &X509_CINF_it;
-#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((LIBPKI_X509_CERT *)v)->cert_info);
 #else
@@ -57,11 +110,6 @@
 		} break;
 
 		case PKI_DATATYPE_X509_CRL : {
-#if OPENSSL_VERSION_NUMBER >= 0x30000000L
-			it = (ASN1_ITEM *) X509_CRL_INFO_it;
-#else
-			it = &X509_CRL_INFO_it;
-#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((PKI_X509_CRL_VALUE *)v)->crl);
 #else
@@ -70,11 +118,6 @@
 		} break;
 
 		case PKI_DATATYPE_X509_REQ : {
-#if OPENSSL_VERSION_NUMBER >= 0x30000000L
-			it = (ASN1_ITEM *) X509_REQ_INFO_it;
-#else
-			it = &X509_REQ_INFO_it;
-#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((LIBPKI_X509_REQ *)v)->req_info);
 #else
@@ -83,11 +126,6 @@
 		} break;
 
 		case PKI_DATATYPE_X509_OCSP_REQ : {
-#if OPENSSL_VERSION_NUMBER >= 0x30000000L
-			it = (ASN1_ITEM *) OCSP_REQINFO_it;
-#else
-			it = &OCSP_REQINFO_it;
-#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((PKI_X509_OCSP_REQ_VALUE *)v)->tbsRequest);
 #else
@@ -96,11 +134,6 @@
 		} break;
 
 		case PKI_DATATYPE_X509_OCSP_RESP : {
-#if OPENSSL_VERSION_NUMBER >= 0x30000000L
-			it = (ASN1_ITEM *) OCSP_RESPDATA_it;
-#else
-			it = &OCSP_RESPDATA_it;
-#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((PKI_OCSP_RESP *)v)->bs->tbsResponseData);
 #else
@@ -109,29 +142,14 @@
 		} break;
 
 		case PKI_DATATYPE_X509_PRQP_REQ : {
-#if OPENSSL_VERSION_NUMBER >= 0x30000000L
-			it = (ASN1_ITEM *) PKI_PRQP_REQ_it;
-#else
-			it = &PKI_PRQP_REQ_it;
-#endif
 			p = ((PKI_X509_PRQP_REQ_VALUE *)v)->requestData;
 		} break;
 
 		case PKI_DATATYPE_X509_PRQP_RESP : {
-#if OPENSSL_VERSION_NUMBER >= 0x30000000L
-			it = (ASN1_ITEM *) PKI_PRQP_RESP_it;
-#else
-			it = &PKI_PRQP_RESP_it;
-#endif
 			p = ((PKI_X509_PRQP_RESP_VALUE *)v)->respData;
 		} break;
 
 		case PKI_DATATYPE_X509_CMS : {
-#if OPENSSL_VERSION_NUMBER >= 0x30000000L
-			it = (ASN1_ITEM *) CMS_ContentInfo_it;
-#else
-			it = &CMS_ContentInfo_it;
-#endif
 			p = NULL;
 		}
 
@@ -156,6 +174,7 @@
 
 }
 
+
 /*! \brief Returns the callbacks for a specific PKI_DATATYPE */
 
 const PKI_X509_CALLBACKS *PKI_X509_CALLBACKS_get (PKI_DATATYPE type, 
@@ -213,6 +232,9 @@
 	// Internal Status
 	ret->status = -1;
 
+	// Internal conversion pointer
+	ret->it = _get_ossl_item(type);
+
 	// All Done
 	return ret;
 }
