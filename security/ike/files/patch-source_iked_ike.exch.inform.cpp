--- source/iked/ike.exch.inform.cpp.orig	2010-12-02 16:06:10 UTC
+++ source/iked/ike.exch.inform.cpp
@@ -399,15 +399,15 @@ long _IKED::inform_chk_hash( IDB_PH1 * ph1, IDB_XCH * 
 	BDATA hash_c;
 	hash_c.size( ph1->hash_size );
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, ( unsigned char * ) &inform->msgid, 4 );
-	HMAC_Update( &ctx_prf, inform->hda.buff(), inform->hda.size() );
-	HMAC_Final( &ctx_prf, hash_c.buff(), NULL );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, ( unsigned char * ) &inform->msgid, 4 );
+	HMAC_Update( ctx_prf, inform->hda.buff(), inform->hda.size() );
+	HMAC_Final( ctx_prf, hash_c.buff(), NULL );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	log.bin(
 		LLOG_DEBUG,
@@ -439,15 +439,15 @@ long _IKED::inform_gen_hash( IDB_PH1 * ph1, IDB_XCH * 
 {
 	inform->hash_l.size( ph1->hash_size );
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, ( unsigned char * ) &inform->msgid, sizeof( inform->msgid ) );
-	HMAC_Update( &ctx_prf, inform->hda.buff(), inform->hda.size() );
-	HMAC_Final( &ctx_prf, inform->hash_l.buff(), 0 );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, ( unsigned char * ) &inform->msgid, sizeof( inform->msgid ) );
+	HMAC_Update( ctx_prf, inform->hda.buff(), inform->hda.size() );
+	HMAC_Final( ctx_prf, inform->hash_l.buff(), 0 );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	log.bin(
 		LLOG_DEBUG,
