--- source/iked/ike.cpp.orig	2009-02-12 02:35:43 UTC
+++ source/iked/ike.cpp
@@ -391,11 +391,11 @@ long _IKED::packet_ike_decrypt( IDB_PH1 * sa, PACKET_I
 	// init cipher key and iv
 	//
 
-	EVP_CIPHER_CTX ctx_cipher;
-	EVP_CIPHER_CTX_init( &ctx_cipher );
+	EVP_CIPHER_CTX *ctx_cipher;
+	ctx_cipher = EVP_CIPHER_CTX_new();
 
 	EVP_CipherInit_ex(
-		&ctx_cipher,
+		ctx_cipher,
 		sa->evp_cipher,
 		NULL,
 		NULL,
@@ -403,11 +403,11 @@ long _IKED::packet_ike_decrypt( IDB_PH1 * sa, PACKET_I
 		0 );
 
 	EVP_CIPHER_CTX_set_key_length(
-		&ctx_cipher,
+		ctx_cipher,
 		( int ) sa->key.size() );
 
 	EVP_CipherInit_ex(
-		&ctx_cipher,
+		ctx_cipher,
 		NULL,
 		NULL,
 		sa->key.buff(),
@@ -419,12 +419,12 @@ long _IKED::packet_ike_decrypt( IDB_PH1 * sa, PACKET_I
 	//
 
 	EVP_Cipher(
-		&ctx_cipher,
+		ctx_cipher,
 		data + sizeof( IKE_HEADER ),
 		data + sizeof( IKE_HEADER ),
 		( int ) size - sizeof( IKE_HEADER ) );
 
-	EVP_CIPHER_CTX_cleanup( &ctx_cipher );
+	EVP_CIPHER_CTX_free( ctx_cipher );
 
 	log.bin(
 		LLOG_DEBUG,
@@ -595,11 +595,11 @@ long _IKED::packet_ike_encrypt( IDB_PH1 * sa, PACKET_I
 	// encrypt all but header
 	//
 
-	EVP_CIPHER_CTX ctx_cipher;
-	EVP_CIPHER_CTX_init( &ctx_cipher );
+	EVP_CIPHER_CTX *ctx_cipher;
+	ctx_cipher = EVP_CIPHER_CTX_new();
 
 	EVP_CipherInit_ex(
-		&ctx_cipher,
+		ctx_cipher,
 		sa->evp_cipher,
 		NULL,
 		NULL,
@@ -607,11 +607,11 @@ long _IKED::packet_ike_encrypt( IDB_PH1 * sa, PACKET_I
 		1 );
 
 	EVP_CIPHER_CTX_set_key_length(
-		&ctx_cipher,
+		ctx_cipher,
 		( int ) sa->key.size() );
 
 	EVP_CipherInit_ex(
-		&ctx_cipher,
+		ctx_cipher,
 		NULL,
 		NULL,
 		sa->key.buff(),
@@ -619,12 +619,12 @@ long _IKED::packet_ike_encrypt( IDB_PH1 * sa, PACKET_I
 		1 );
 
 	EVP_Cipher(
-		&ctx_cipher,
+		ctx_cipher,
 		data + sizeof( IKE_HEADER ),
 		data + sizeof( IKE_HEADER ),
 		( int ) size - sizeof( IKE_HEADER ) );
 
-	EVP_CIPHER_CTX_cleanup( &ctx_cipher );
+	EVP_CIPHER_CTX_free( ctx_cipher );
 
 	//
 	// store cipher iv data
