--- source/iked/ike.exch.config.cpp.orig	2013-04-07 16:28:06 UTC
+++ source/iked/ike.exch.config.cpp
@@ -2481,15 +2481,15 @@ long _IKED::config_chk_hash( IDB_PH1 * ph1, IDB_CFG * 
 	BDATA hash_c;
 	hash_c.size( ph1->hash_size );
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, ( unsigned char * ) &msgid, 4 );
-	HMAC_Update( &ctx_prf, cfg->hda.buff(), cfg->hda.size() );
-	HMAC_Final( &ctx_prf, hash_c.buff(), NULL );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, ( unsigned char * ) &msgid, 4 );
+	HMAC_Update( ctx_prf, cfg->hda.buff(), cfg->hda.size() );
+	HMAC_Final( ctx_prf, hash_c.buff(), NULL );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	log.bin(
 		LLOG_DEBUG,
@@ -2543,15 +2543,15 @@ long _IKED::config_message_send( IDB_PH1 * ph1, IDB_CF
 	// create message authentication hash
 	//
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, ( unsigned char * ) &cfg->msgid, sizeof( cfg->msgid ) );
-	HMAC_Update( &ctx_prf, packet.buff() + beg, end - beg );
-	HMAC_Final( &ctx_prf, hash.buff(), 0 );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, ( unsigned char * ) &cfg->msgid, sizeof( cfg->msgid ) );
+	HMAC_Update( ctx_prf, packet.buff() + beg, end - beg );
+	HMAC_Final( ctx_prf, hash.buff(), 0 );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	memcpy( packet.buff() + off + 4, hash.buff(), hash.size() );
 
