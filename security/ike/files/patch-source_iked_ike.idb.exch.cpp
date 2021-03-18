--- source/iked/ike.idb.exch.cpp.orig	2011-01-15 22:09:32 UTC
+++ source/iked/ike.idb.exch.cpp
@@ -134,12 +134,13 @@ bool _IDB_XCH::new_msgiv( IDB_PH1 * ph1 )
 	unsigned char iv_data[ EVP_MAX_MD_SIZE ];
 	unsigned long iv_size = EVP_CIPHER_iv_length( ph1->evp_cipher );
 
-	EVP_MD_CTX ctx_hash;
-	EVP_DigestInit( &ctx_hash, ph1->evp_hash );
-	EVP_DigestUpdate( &ctx_hash, ph1->iv.buff(), ph1->iv.size() );
-	EVP_DigestUpdate( &ctx_hash, &msgid, 4 );
-	EVP_DigestFinal( &ctx_hash, iv_data, NULL );
-	EVP_MD_CTX_cleanup( &ctx_hash );
+	EVP_MD_CTX *ctx_hash;
+	ctx_hash = EVP_MD_CTX_new();
+	EVP_DigestInit( ctx_hash, ph1->evp_hash );
+	EVP_DigestUpdate( ctx_hash, ph1->iv.buff(), ph1->iv.size() );
+	EVP_DigestUpdate( ctx_hash, &msgid, 4 );
+	EVP_DigestFinal( ctx_hash, iv_data, NULL );
+	EVP_MD_CTX_free( ctx_hash );
 
 	iv.set( iv_data, iv_size );
 
