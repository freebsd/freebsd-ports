--- source/iked/ike.keyfile.cpp.orig	2012-12-15 22:14:32 UTC
+++ source/iked/ike.keyfile.cpp
@@ -663,15 +663,19 @@ static int verify_cb( int ok, X509_STORE_CTX * store_c
 	{
 		long ll = LLOG_ERROR;
 		char name[ 512 ];
+		int error, error_depth;
 
-		X509_NAME * x509_name = X509_get_subject_name( store_ctx->current_cert );
+		X509_NAME * x509_name = X509_get_subject_name( X509_STORE_CTX_get_current_cert(store_ctx) );
 
 		X509_NAME_oneline(
 			x509_name,
 			name,
 			512 );
+
+		error = X509_STORE_CTX_get_error(store_ctx);
+		error_depth = X509_STORE_CTX_get_error_depth(store_ctx);
 
-		switch( store_ctx->error )
+		switch( error )
 		{
 			case X509_V_ERR_UNABLE_TO_GET_CRL:
 				ok = 1;
@@ -683,9 +687,9 @@ static int verify_cb( int ok, X509_STORE_CTX * store_c
 			ll,
 			"ii : %s(%d) at depth:%d\n"
 			"ii : subject :%s\n",
-			X509_verify_cert_error_string( store_ctx->error ),
-			store_ctx->error,
-			store_ctx->error_depth,
+			X509_verify_cert_error_string( error ),
+			error,
+			error_depth,
 			name );
 	}
 
@@ -857,7 +861,7 @@ bool prvkey_rsa_load_pem( BDATA & prvkey, FILE * fp, B
 	if( evp_pkey == NULL )
 		return false;
 
-	bool converted = prvkey_rsa_2_bdata( prvkey, evp_pkey->pkey.rsa );
+	bool converted = prvkey_rsa_2_bdata( prvkey, EVP_PKEY_get0_RSA(evp_pkey) );
 	EVP_PKEY_free( evp_pkey );
 
 	return converted;
@@ -883,7 +887,7 @@ bool prvkey_rsa_load_p12( BDATA & prvkey, FILE * fp, B
 	if( evp_pkey == NULL )
 		return false;
 
-	bool converted = prvkey_rsa_2_bdata( prvkey, evp_pkey->pkey.rsa );
+	bool converted = prvkey_rsa_2_bdata( prvkey, EVP_PKEY_get0_RSA(evp_pkey) );
 	EVP_PKEY_free( evp_pkey );
 
 	return converted;
@@ -939,7 +943,7 @@ bool prvkey_rsa_load_pem( BDATA & prvkey, BDATA & inpu
 	if( evp_pkey == NULL )
 		return false;
 
-	bool converted = prvkey_rsa_2_bdata( prvkey, evp_pkey->pkey.rsa );
+	bool converted = prvkey_rsa_2_bdata( prvkey, EVP_PKEY_get0_RSA(evp_pkey) );
 	EVP_PKEY_free( evp_pkey );
 
 	return converted;
@@ -976,7 +980,7 @@ bool prvkey_rsa_load_p12( BDATA & prvkey, BDATA & inpu
 	if( evp_pkey == NULL )
 		return false;
 
-	bool converted = prvkey_rsa_2_bdata( prvkey, evp_pkey->pkey.rsa );
+	bool converted = prvkey_rsa_2_bdata( prvkey, EVP_PKEY_get0_RSA(evp_pkey) );
 	EVP_PKEY_free( evp_pkey );
 
 	return converted;
@@ -1010,7 +1014,7 @@ bool _IKED::pubkey_rsa_read( BDATA & cert, BDATA & pub
 	if( evp_pkey == NULL )
 		return false;
 
-	bool result = pubkey_rsa_2_bdata( pubkey, evp_pkey->pkey.rsa );
+	bool result = pubkey_rsa_2_bdata( pubkey, EVP_PKEY_get0_RSA(evp_pkey) );
 
 	EVP_PKEY_free( evp_pkey );
 
