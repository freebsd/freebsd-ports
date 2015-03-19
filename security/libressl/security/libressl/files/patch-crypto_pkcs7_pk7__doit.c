--- crypto/pkcs7/pk7_doit.c.orig	2015-02-09 01:31:52 UTC
+++ crypto/pkcs7/pk7_doit.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: pk7_doit.c,v 1.30 2014/10/22 13:02:04 jsing Exp $ */
+/* $OpenBSD: pk7_doit.c,v 1.31 2015/02/07 13:19:15 doug Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -261,6 +261,28 @@ PKCS7_dataInit(PKCS7 *p7, BIO *bio)
 	PKCS7_RECIP_INFO *ri = NULL;
 	ASN1_OCTET_STRING *os = NULL;
 
+	if (p7 == NULL) {
+		PKCS7err(PKCS7_F_PKCS7_DATAINIT, PKCS7_R_INVALID_NULL_POINTER);
+		return NULL;
+	}
+
+	/*
+	 * The content field in the PKCS7 ContentInfo is optional,
+	 * but that really only applies to inner content (precisely,
+	 * detached signatures).
+	 *
+	 * When reading content, missing outer content is therefore
+	 * treated as an error.
+	 *
+	 * When creating content, PKCS7_content_new() must be called
+	 * before calling this method, so a NULL p7->d is always
+	 * an error.
+	 */
+	if (p7->d.ptr == NULL) {
+		PKCS7err(PKCS7_F_PKCS7_DATAINIT, PKCS7_R_NO_CONTENT);
+		return NULL;
+	}
+
 	i = OBJ_obj2nid(p7->type);
 	p7->state = PKCS7_S_HEADER;
 
@@ -417,6 +439,17 @@ PKCS7_dataDecode(PKCS7 *p7, EVP_PKEY *pk
 	unsigned char *ek = NULL, *tkey = NULL;
 	int eklen = 0, tkeylen = 0;
 
+	if (p7 == NULL) {
+		PKCS7err(PKCS7_F_PKCS7_DATADECODE,
+		    PKCS7_R_INVALID_NULL_POINTER);
+		return NULL;
+	}
+
+	if (p7->d.ptr == NULL) {
+		PKCS7err(PKCS7_F_PKCS7_DATADECODE, PKCS7_R_NO_CONTENT);
+		return NULL;
+	}
+
 	i = OBJ_obj2nid(p7->type);
 	p7->state = PKCS7_S_HEADER;
 
@@ -691,6 +724,17 @@ PKCS7_dataFinal(PKCS7 *p7, BIO *bio)
 	STACK_OF(PKCS7_SIGNER_INFO) *si_sk = NULL;
 	ASN1_OCTET_STRING *os = NULL;
 
+	if (p7 == NULL) {
+		PKCS7err(PKCS7_F_PKCS7_DATAFINAL,
+		    PKCS7_R_INVALID_NULL_POINTER);
+		return 0;
+	}
+
+	if (p7->d.ptr == NULL) {
+		PKCS7err(PKCS7_F_PKCS7_DATAFINAL, PKCS7_R_NO_CONTENT);
+		return 0;
+	}
+
 	EVP_MD_CTX_init(&ctx_tmp);
 	i = OBJ_obj2nid(p7->type);
 	p7->state = PKCS7_S_HEADER;
@@ -736,6 +780,7 @@ PKCS7_dataFinal(PKCS7 *p7, BIO *bio)
 		/* If detached data then the content is excluded */
 		if (PKCS7_type_is_data(p7->d.sign->contents) && p7->detached) {
 			M_ASN1_OCTET_STRING_free(os);
+			os = NULL;
 			p7->d.sign->contents->d.data = NULL;
 		}
 		break;
@@ -750,6 +795,7 @@ PKCS7_dataFinal(PKCS7 *p7, BIO *bio)
 		if (PKCS7_type_is_data(p7->d.digest->contents) &&
 		    p7->detached) {
 			M_ASN1_OCTET_STRING_free(os);
+			os = NULL;
 			p7->d.digest->contents->d.data = NULL;
 		}
 		break;
@@ -815,22 +861,32 @@ PKCS7_dataFinal(PKCS7 *p7, BIO *bio)
 		M_ASN1_OCTET_STRING_set(p7->d.digest->digest, md_data, md_len);
 	}
 
-	if (!PKCS7_is_detached(p7) && !(os->flags & ASN1_STRING_FLAG_NDEF)) {
-		char *cont;
-		long contlen;
-		btmp = BIO_find_type(bio, BIO_TYPE_MEM);
-		if (btmp == NULL) {
-			PKCS7err(PKCS7_F_PKCS7_DATAFINAL,
-			    PKCS7_R_UNABLE_TO_FIND_MEM_BIO);
+	if (!PKCS7_is_detached(p7)) {
+		/*
+		 * NOTE: only reach os == NULL here because detached
+		 * digested data support is broken?
+		 */
+		if (os == NULL)
 			goto err;
+		if (!(os->flags & ASN1_STRING_FLAG_NDEF)) {
+			char *cont;
+			long contlen;
+
+			btmp = BIO_find_type(bio, BIO_TYPE_MEM);
+			if (btmp == NULL) {
+				PKCS7err(PKCS7_F_PKCS7_DATAFINAL,
+				    PKCS7_R_UNABLE_TO_FIND_MEM_BIO);
+				goto err;
+			}
+			contlen = BIO_get_mem_data(btmp, &cont);
+			/*
+			 * Mark the BIO read only then we can use its copy
+			 * of the data instead of making an extra copy.
+			 */
+			BIO_set_flags(btmp, BIO_FLAGS_MEM_RDONLY);
+			BIO_set_mem_eof_return(btmp, 0);
+			ASN1_STRING_set0(os, (unsigned char *)cont, contlen);
 		}
-		contlen = BIO_get_mem_data(btmp, &cont);
-		/* Mark the BIO read only then we can use its copy of the data
-		 * instead of making an extra copy.
-		 */
-		BIO_set_flags(btmp, BIO_FLAGS_MEM_RDONLY);
-		BIO_set_mem_eof_return(btmp, 0);
-		ASN1_STRING_set0(os, (unsigned char *)cont, contlen);
 	}
 	ret = 1;
 err:
@@ -905,6 +961,17 @@ PKCS7_dataVerify(X509_STORE *cert_store,
 	STACK_OF(X509) *cert;
 	X509 *x509;
 
+	if (p7 == NULL) {
+		PKCS7err(PKCS7_F_PKCS7_DATAVERIFY,
+		    PKCS7_R_INVALID_NULL_POINTER);
+		return 0;
+	}
+
+	if (p7->d.ptr == NULL) {
+		PKCS7err(PKCS7_F_PKCS7_DATAVERIFY, PKCS7_R_NO_CONTENT);
+		return 0;
+	}
+
 	if (PKCS7_type_is_signed(p7)) {
 		cert = p7->d.sign->cert;
 	} else if (PKCS7_type_is_signedAndEnveloped(p7)) {
@@ -941,6 +1008,7 @@ PKCS7_dataVerify(X509_STORE *cert_store,
 
 	return PKCS7_signatureVerify(bio, p7, si, x509);
 err:
+	
 	return ret;
 }
 
