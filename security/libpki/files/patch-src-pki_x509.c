--- src/pki_x509.c.orig	2023-06-27 08:58:28.488591000 +0200
+++ src/pki_x509.c	2023-06-27 13:17:52.661803000 +0200
@@ -44,7 +44,11 @@
 	switch (type) {
 
 		case PKI_DATATYPE_X509_CERT : {
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+		        it = (ASN1_ITEM *) X509_CINF_it;
+#else
 			it = &X509_CINF_it;
+#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((LIBPKI_X509_CERT *)v)->cert_info);
 #else
@@ -53,7 +57,11 @@
 		} break;
 
 		case PKI_DATATYPE_X509_CRL : {
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+			it = (ASN1_ITEM *) X509_CRL_INFO_it;
+#else
 			it = &X509_CRL_INFO_it;
+#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((PKI_X509_CRL_VALUE *)v)->crl);
 #else
@@ -62,7 +70,11 @@
 		} break;
 
 		case PKI_DATATYPE_X509_REQ : {
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+			it = (ASN1_ITEM *) X509_REQ_INFO_it;
+#else
 			it = &X509_REQ_INFO_it;
+#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((LIBPKI_X509_REQ *)v)->req_info);
 #else
@@ -71,7 +83,11 @@
 		} break;
 
 		case PKI_DATATYPE_X509_OCSP_REQ : {
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+			it = (ASN1_ITEM *) OCSP_REQINFO_it;
+#else
 			it = &OCSP_REQINFO_it;
+#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((PKI_X509_OCSP_REQ_VALUE *)v)->tbsRequest);
 #else
@@ -80,7 +96,11 @@
 		} break;
 
 		case PKI_DATATYPE_X509_OCSP_RESP : {
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+			it = (ASN1_ITEM *) OCSP_RESPDATA_it;
+#else
 			it = &OCSP_RESPDATA_it;
+#endif
 #if OPENSSL_VERSION_NUMBER > 0x1010000fL
 			p = &(((PKI_OCSP_RESP *)v)->bs->tbsResponseData);
 #else
@@ -89,17 +109,29 @@
 		} break;
 
 		case PKI_DATATYPE_X509_PRQP_REQ : {
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+			it = (ASN1_ITEM *) PKI_PRQP_REQ_it;
+#else
 			it = &PKI_PRQP_REQ_it;
+#endif
 			p = ((PKI_X509_PRQP_REQ_VALUE *)v)->requestData;
 		} break;
 
 		case PKI_DATATYPE_X509_PRQP_RESP : {
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+			it = (ASN1_ITEM *) PKI_PRQP_RESP_it;
+#else
 			it = &PKI_PRQP_RESP_it;
+#endif
 			p = ((PKI_X509_PRQP_RESP_VALUE *)v)->respData;
 		} break;
 
 		case PKI_DATATYPE_X509_CMS : {
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+			it = (ASN1_ITEM *) CMS_ContentInfo_it;
+#else
 			it = &CMS_ContentInfo_it;
+#endif
 			p = NULL;
 		}
 
