--- source/iked/ike.exch.phase2.cpp.orig	2010-12-22 21:35:36 UTC
+++ source/iked/ike.exch.phase2.cpp
@@ -1008,14 +1008,14 @@ long _IKED::phase2_gen_hash_i( IDB_PH1 * ph1, IDB_PH2 
 
 	hash.size( ph1->hash_size );
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, input.buff(), input.size() );
-	HMAC_Final( &ctx_prf, hash.buff(), NULL );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, input.buff(), input.size() );
+	HMAC_Final( ctx_prf, hash.buff(), NULL );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	log.bin(
 		LLOG_DEBUG,
@@ -1048,14 +1048,14 @@ long _IKED::phase2_gen_hash_r( IDB_PH1 * ph1, IDB_PH2 
 
 	hash.size( ph1->hash_size );
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, input.buff(), input.size() );
-	HMAC_Final( &ctx_prf, hash.buff(), NULL );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, input.buff(), input.size() );
+	HMAC_Final( ctx_prf, hash.buff(), NULL );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	log.bin(
 		LLOG_DEBUG,
@@ -1093,14 +1093,14 @@ long _IKED::phase2_gen_hash_p( IDB_PH1 * ph1, IDB_PH2 
 
 	hash.size( ph1->hash_size );
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, input.buff(), input.size() );
-	HMAC_Final( &ctx_prf, hash.buff(), 0 );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid_a.buff(), ( int ) ph1->skeyid_a.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, input.buff(), input.size() );
+	HMAC_Final( ctx_prf, hash.buff(), 0 );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	log.bin(
 		LLOG_DEBUG,
@@ -1555,7 +1555,7 @@ long _IKED::phase2_gen_keys( IDB_PH1 * ph1, IDB_PH2 * 
 		{
 			BDATA prv;
 			prv.size( ph2->dh_size );
-			BN_bn2bin( ph2->dh->priv_key, prv.buff() );
+			BN_bn2bin( DH_get0_priv_key( ph2->dh ), prv.buff() );
 
 			log.bin(
 				LLOG_DECODE,
@@ -1817,56 +1817,56 @@ long _IKED::phase2_gen_keys( IDB_PH1 * ph1, IDB_PH2 * 
 	// K3 = prf( SKEYID_d, K2 | [ g(qm)^xy | ] protocol | SPI | Ni_b | Nr_b )
 	//
 	
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid_d.buff(), ( int ) ph1->skeyid_d.size(), ph1->evp_hash, NULL );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid_d.buff(), ( int ) ph1->skeyid_d.size(), ph1->evp_hash, NULL );
 
 	if( ph2->dhgr_id )
-		HMAC_Update( &ctx_prf, shared.buff(), shared.size() );
+		HMAC_Update( ctx_prf, shared.buff(), shared.size() );
 
-	HMAC_Update( &ctx_prf, ( unsigned char * ) &proposal->proto, 1 );
-	HMAC_Update( &ctx_prf, ( unsigned char * ) &proposal->spi, 4 );
+	HMAC_Update( ctx_prf, ( unsigned char * ) &proposal->proto, 1 );
+	HMAC_Update( ctx_prf, ( unsigned char * ) &proposal->spi, 4 );
 
 	if( ph2->initiator )
 	{
-		HMAC_Update( &ctx_prf, ph2->nonce_l.buff(), ph2->nonce_l.size() );
-		HMAC_Update( &ctx_prf, ph2->nonce_r.buff(), ph2->nonce_r.size() );
+		HMAC_Update( ctx_prf, ph2->nonce_l.buff(), ph2->nonce_l.size() );
+		HMAC_Update( ctx_prf, ph2->nonce_r.buff(), ph2->nonce_r.size() );
 	}
 	else
 	{
-		HMAC_Update( &ctx_prf, ph2->nonce_r.buff(), ph2->nonce_r.size() );
-		HMAC_Update( &ctx_prf, ph2->nonce_l.buff(), ph2->nonce_l.size() );
+		HMAC_Update( ctx_prf, ph2->nonce_r.buff(), ph2->nonce_r.size() );
+		HMAC_Update( ctx_prf, ph2->nonce_l.buff(), ph2->nonce_l.size() );
 	}
 
-	HMAC_Final( &ctx_prf, key_data, NULL );
+	HMAC_Final( ctx_prf, key_data, NULL );
 
 	for( long size = skeyid_size; size < key_size; size += skeyid_size )
 	{
-		HMAC_Init_ex( &ctx_prf, ph1->skeyid_d.buff(), ( int ) ph1->skeyid_d.size(), ph1->evp_hash, NULL );
-		HMAC_Update( &ctx_prf, key_data + size - skeyid_size, skeyid_size );
+		HMAC_Init_ex( ctx_prf, ph1->skeyid_d.buff(), ( int ) ph1->skeyid_d.size(), ph1->evp_hash, NULL );
+		HMAC_Update( ctx_prf, key_data + size - skeyid_size, skeyid_size );
 
 		if( ph2->dhgr_id )
-			HMAC_Update( &ctx_prf, shared.buff(), shared.size() );
+			HMAC_Update( ctx_prf, shared.buff(), shared.size() );
 
-		HMAC_Update( &ctx_prf, ( unsigned char * ) &proposal->proto, 1 );
-		HMAC_Update( &ctx_prf, ( unsigned char * ) &proposal->spi, 4 );
+		HMAC_Update( ctx_prf, ( unsigned char * ) &proposal->proto, 1 );
+		HMAC_Update( ctx_prf, ( unsigned char * ) &proposal->spi, 4 );
 
 		if( ph2->initiator )
 		{
-			HMAC_Update( &ctx_prf, ph2->nonce_l.buff(), ph2->nonce_l.size() );
-			HMAC_Update( &ctx_prf, ph2->nonce_r.buff(), ph2->nonce_r.size() );
+			HMAC_Update( ctx_prf, ph2->nonce_l.buff(), ph2->nonce_l.size() );
+			HMAC_Update( ctx_prf, ph2->nonce_r.buff(), ph2->nonce_r.size() );
 		}
 		else
 		{
-			HMAC_Update( &ctx_prf, ph2->nonce_r.buff(), ph2->nonce_r.size() );
-			HMAC_Update( &ctx_prf, ph2->nonce_l.buff(), ph2->nonce_l.size() );
+			HMAC_Update( ctx_prf, ph2->nonce_r.buff(), ph2->nonce_r.size() );
+			HMAC_Update( ctx_prf, ph2->nonce_l.buff(), ph2->nonce_l.size() );
 		}
 
-		HMAC_Final( &ctx_prf, key_data + size, 0 );
+		HMAC_Final( ctx_prf, key_data + size, 0 );
 	}
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	//
 	// separate encrypt and auth key data
