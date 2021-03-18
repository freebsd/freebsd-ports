--- source/iked/ike.exch.phase1.cpp.orig	2012-02-08 05:09:35 UTC
+++ source/iked/ike.exch.phase1.cpp
@@ -1044,14 +1044,14 @@ long _IKED::process_phase1_send( IDB_PH1 * ph1 )
 								BDATA psk_hash;
 								psk_hash.size( ph1->hash_size );
 
-								HMAC_CTX ctx_prf;
-								HMAC_CTX_init( &ctx_prf );
+								HMAC_CTX *ctx_prf;
+								ctx_prf = HMAC_CTX_new();
 
-								HMAC_Init_ex( &ctx_prf, ph1->skeyid.buff(), ( int ) ph1->skeyid.size(), ph1->evp_hash, NULL );
-								HMAC_Update( &ctx_prf, ph1->tunnel->peer->psk.buff(), ph1->tunnel->peer->psk.size() );
-								HMAC_Final( &ctx_prf, psk_hash.buff(), NULL );
+								HMAC_Init_ex( ctx_prf, ph1->skeyid.buff(), ( int ) ph1->skeyid.size(), ph1->evp_hash, NULL );
+								HMAC_Update( ctx_prf, ph1->tunnel->peer->psk.buff(), ph1->tunnel->peer->psk.size() );
+								HMAC_Final( ctx_prf, psk_hash.buff(), NULL );
 
-								HMAC_CTX_cleanup( &ctx_prf );
+								HMAC_CTX_free( ctx_prf );
 
 								//
 								// add the notification payload
@@ -1557,7 +1557,7 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 	{
 		BDATA prv;
 		prv.size( ph1->dh_size );
-		BN_bn2bin( ph1->dh->priv_key, prv.buff() );
+		BN_bn2bin( DH_get0_priv_key( ph1->dh ), prv.buff() );
 
 		log.bin(
 			LLOG_DECODE,
@@ -1656,25 +1656,25 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 		case XAUTH_AUTH_INIT_PSK:
 		case XAUTH_AUTH_RESP_PSK:
 		{
-			HMAC_CTX ctx_prf;
-			HMAC_CTX_init( &ctx_prf );
+			HMAC_CTX *ctx_prf;
+			ctx_prf = HMAC_CTX_new();
 
-			HMAC_Init_ex( &ctx_prf, ph1->tunnel->peer->psk.buff(), ( int ) ph1->tunnel->peer->psk.size(), ph1->evp_hash, NULL );
+			HMAC_Init_ex( ctx_prf, ph1->tunnel->peer->psk.buff(), ( int ) ph1->tunnel->peer->psk.size(), ph1->evp_hash, NULL );
 
 			if( ph1->initiator )
 			{
-				HMAC_Update( &ctx_prf, ph1->nonce_l.buff(), ph1->nonce_l.size() );
-				HMAC_Update( &ctx_prf, ph1->nonce_r.buff(), ph1->nonce_r.size() );
+				HMAC_Update( ctx_prf, ph1->nonce_l.buff(), ph1->nonce_l.size() );
+				HMAC_Update( ctx_prf, ph1->nonce_r.buff(), ph1->nonce_r.size() );
 			}
 			else
 			{
-				HMAC_Update( &ctx_prf, ph1->nonce_r.buff(), ph1->nonce_r.size() );
-				HMAC_Update( &ctx_prf, ph1->nonce_l.buff(), ph1->nonce_l.size() );
+				HMAC_Update( ctx_prf, ph1->nonce_r.buff(), ph1->nonce_r.size() );
+				HMAC_Update( ctx_prf, ph1->nonce_l.buff(), ph1->nonce_l.size() );
 			}
 
-			HMAC_Final( &ctx_prf, skeyid_data, NULL );
+			HMAC_Final( ctx_prf, skeyid_data, NULL );
 
-			HMAC_CTX_cleanup( &ctx_prf );
+			HMAC_CTX_free( ctx_prf );
 
 			break;
 		}
@@ -1704,14 +1704,14 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 				nonce.add( ph1->nonce_l );
 			}
 
-			HMAC_CTX ctx_prf;
-			HMAC_CTX_init( &ctx_prf );
+			HMAC_CTX *ctx_prf;
+			ctx_prf = HMAC_CTX_new();
 
-			HMAC_Init_ex( &ctx_prf, nonce.buff(), ( int ) nonce.size(), ph1->evp_hash, NULL );
-			HMAC_Update( &ctx_prf, shared.buff(), shared.size() );
-			HMAC_Final( &ctx_prf, skeyid_data, NULL );
+			HMAC_Init_ex( ctx_prf, nonce.buff(), ( int ) nonce.size(), ph1->evp_hash, NULL );
+			HMAC_Update( ctx_prf, shared.buff(), shared.size() );
+			HMAC_Final( ctx_prf, skeyid_data, NULL );
 
-			HMAC_CTX_cleanup( &ctx_prf );
+			HMAC_CTX_free( ctx_prf );
 
 			break;
 		}	
@@ -1730,15 +1730,15 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 	// compute SKEYID_d
 	//
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid.buff(), ( int ) ph1->skeyid.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, shared.buff(), shared.size() );
-	HMAC_Update( &ctx_prf, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, ( unsigned char * ) "\0", 1 );
-	HMAC_Final( &ctx_prf, skeyid_data, NULL );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid.buff(), ( int ) ph1->skeyid.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, shared.buff(), shared.size() );
+	HMAC_Update( ctx_prf, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, ( unsigned char * ) "\0", 1 );
+	HMAC_Final( ctx_prf, skeyid_data, NULL );
 
 	ph1->skeyid_d.set( skeyid_data, skeyid_size );
 
@@ -1753,13 +1753,13 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 	// compute SKEYID_a
 	//
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid.buff(), ( int ) ph1->skeyid.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, skeyid_data, skeyid_size );
-	HMAC_Update( &ctx_prf, shared.buff(), shared.size() );
-	HMAC_Update( &ctx_prf, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, ( unsigned char * ) "\1", 1 );
-	HMAC_Final( &ctx_prf, skeyid_data, NULL );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid.buff(), ( int ) ph1->skeyid.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, skeyid_data, skeyid_size );
+	HMAC_Update( ctx_prf, shared.buff(), shared.size() );
+	HMAC_Update( ctx_prf, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, ( unsigned char * ) "\1", 1 );
+	HMAC_Final( ctx_prf, skeyid_data, NULL );
 
 	ph1->skeyid_a.set( skeyid_data, skeyid_size );
 
@@ -1774,13 +1774,13 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 	// compute SKEYID_e
 	//
 
-	HMAC_Init_ex( &ctx_prf, ph1->skeyid.buff(), ( int ) ph1->skeyid.size(), ph1->evp_hash, NULL );
-	HMAC_Update( &ctx_prf, skeyid_data, skeyid_size );
-	HMAC_Update( &ctx_prf, shared.buff(), shared.size() );
-	HMAC_Update( &ctx_prf, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, ( unsigned char * ) "\2", 1 );
-	HMAC_Final( &ctx_prf, skeyid_data, NULL );
+	HMAC_Init_ex( ctx_prf, ph1->skeyid.buff(), ( int ) ph1->skeyid.size(), ph1->evp_hash, NULL );
+	HMAC_Update( ctx_prf, skeyid_data, skeyid_size );
+	HMAC_Update( ctx_prf, shared.buff(), shared.size() );
+	HMAC_Update( ctx_prf, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, ( unsigned char * ) "\2", 1 );
+	HMAC_Final( ctx_prf, skeyid_data, NULL );
 
 	ph1->skeyid_e.set( skeyid_data, skeyid_size );
 
@@ -1821,15 +1821,15 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 
 		// create extended key data
 
-		HMAC_Init_ex( &ctx_prf, skeyid_data, skeyid_size, ph1->evp_hash, NULL );
-		HMAC_Update( &ctx_prf, ( unsigned char * ) "\0", 1 );
-		HMAC_Final( &ctx_prf, key_data, NULL );
+		HMAC_Init_ex( ctx_prf, skeyid_data, skeyid_size, ph1->evp_hash, NULL );
+		HMAC_Update( ctx_prf, ( unsigned char * ) "\0", 1 );
+		HMAC_Final( ctx_prf, key_data, NULL );
 
 		for( long size = skeyid_size; size < key_size; size += skeyid_size )
 		{
-			HMAC_Init_ex( &ctx_prf, skeyid_data, skeyid_size, ph1->evp_hash, NULL );
-			HMAC_Update( &ctx_prf, key_data + size - skeyid_size, skeyid_size );
-			HMAC_Final( &ctx_prf, key_data + size, NULL );
+			HMAC_Init_ex( ctx_prf, skeyid_data, skeyid_size, ph1->evp_hash, NULL );
+			HMAC_Update( ctx_prf, key_data + size - skeyid_size, skeyid_size );
+			HMAC_Final( ctx_prf, key_data + size, NULL );
 		}
 	}
 	else
@@ -1839,7 +1839,7 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 		memcpy( key_data, skeyid_data, key_size );
 	}
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	if( proposal->ciph_kl )
 		key_size = ( proposal->ciph_kl + 7 ) / 8;
@@ -1860,22 +1860,23 @@ long _IKED::phase1_gen_keys( IDB_PH1 * ph1 )
 	unsigned char iv_data[ HMAC_MAX_MD_CBLOCK ];
 	unsigned long iv_size = EVP_CIPHER_iv_length( ph1->evp_cipher );
 
-	EVP_MD_CTX ctx_hash;
-	EVP_DigestInit( &ctx_hash, ph1->evp_hash );
+	EVP_MD_CTX *ctx_hash;
+	ctx_hash = EVP_MD_CTX_new();
+	EVP_DigestInit( ctx_hash, ph1->evp_hash );
 
 	if( ph1->initiator )
 	{
-		EVP_DigestUpdate( &ctx_hash, ph1->xl.buff(), ph1->xl.size() );
-		EVP_DigestUpdate( &ctx_hash, ph1->xr.buff(), ph1->xr.size() );
+		EVP_DigestUpdate( ctx_hash, ph1->xl.buff(), ph1->xl.size() );
+		EVP_DigestUpdate( ctx_hash, ph1->xr.buff(), ph1->xr.size() );
 	}
 	else
 	{
-		EVP_DigestUpdate( &ctx_hash, ph1->xr.buff(), ph1->xr.size() );
-		EVP_DigestUpdate( &ctx_hash, ph1->xl.buff(), ph1->xl.size() );
+		EVP_DigestUpdate( ctx_hash, ph1->xr.buff(), ph1->xr.size() );
+		EVP_DigestUpdate( ctx_hash, ph1->xl.buff(), ph1->xl.size() );
 	}
 
-	EVP_DigestFinal( &ctx_hash, iv_data, NULL );
-	EVP_MD_CTX_cleanup( &ctx_hash );
+	EVP_DigestFinal( ctx_hash, iv_data, NULL );
+	EVP_MD_CTX_free( ctx_hash );
 
 	ph1->iv.set( iv_data, iv_size );
 
@@ -1903,29 +1904,29 @@ long _IKED::phase1_gen_hash_i( IDB_PH1 * sa, BDATA & h
 
 	hash.size( sa->hash_size );
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, sa->skeyid.buff(), ( int ) sa->skeyid.size(), sa->evp_hash, NULL );
+	HMAC_Init_ex( ctx_prf, sa->skeyid.buff(), ( int ) sa->skeyid.size(), sa->evp_hash, NULL );
 
 	if( sa->initiator )
 	{
-		HMAC_Update( &ctx_prf, sa->xl.buff(), sa->xl.size() );
-		HMAC_Update( &ctx_prf, sa->xr.buff(), sa->xr.size() );
+		HMAC_Update( ctx_prf, sa->xl.buff(), sa->xl.size() );
+		HMAC_Update( ctx_prf, sa->xr.buff(), sa->xr.size() );
 	}
 	else
 	{
-		HMAC_Update( &ctx_prf, sa->xr.buff(), sa->xr.size() );
-		HMAC_Update( &ctx_prf, sa->xl.buff(), sa->xl.size() );
+		HMAC_Update( ctx_prf, sa->xr.buff(), sa->xr.size() );
+		HMAC_Update( ctx_prf, sa->xl.buff(), sa->xl.size() );
 	}
 
-	HMAC_Update( &ctx_prf, sa->cookies.i, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, sa->cookies.r, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, sa->hda.buff(), sa->hda.size() );
-	HMAC_Update( &ctx_prf, sa->idi.buff(), sa->idi.size() );
-	HMAC_Final( &ctx_prf, hash.buff(), NULL );
+	HMAC_Update( ctx_prf, sa->cookies.i, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, sa->cookies.r, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, sa->hda.buff(), sa->hda.size() );
+	HMAC_Update( ctx_prf, sa->idi.buff(), sa->idi.size() );
+	HMAC_Final( ctx_prf, hash.buff(), NULL );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	log.bin(
 		LLOG_DEBUG,
@@ -1945,29 +1946,29 @@ long _IKED::phase1_gen_hash_r( IDB_PH1 * sa, BDATA & h
 
 	hash.size( sa->hash_size );
 
-	HMAC_CTX ctx_prf;
-	HMAC_CTX_init( &ctx_prf );
+	HMAC_CTX *ctx_prf;
+	ctx_prf = HMAC_CTX_new();
 
-	HMAC_Init_ex( &ctx_prf, sa->skeyid.buff(), ( int ) sa->skeyid.size(), sa->evp_hash, NULL );
+	HMAC_Init_ex( ctx_prf, sa->skeyid.buff(), ( int ) sa->skeyid.size(), sa->evp_hash, NULL );
 
 	if( sa->initiator )
 	{
-		HMAC_Update( &ctx_prf, sa->xr.buff(), sa->xr.size() );
-		HMAC_Update( &ctx_prf, sa->xl.buff(), sa->xl.size() );
+		HMAC_Update( ctx_prf, sa->xr.buff(), sa->xr.size() );
+		HMAC_Update( ctx_prf, sa->xl.buff(), sa->xl.size() );
 	}
 	else
 	{
-		HMAC_Update( &ctx_prf, sa->xl.buff(), sa->xl.size() );
-		HMAC_Update( &ctx_prf, sa->xr.buff(), sa->xr.size() );
+		HMAC_Update( ctx_prf, sa->xl.buff(), sa->xl.size() );
+		HMAC_Update( ctx_prf, sa->xr.buff(), sa->xr.size() );
 	}
 
-	HMAC_Update( &ctx_prf, sa->cookies.r, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, sa->cookies.i, ISAKMP_COOKIE_SIZE );
-	HMAC_Update( &ctx_prf, sa->hda.buff(), sa->hda.size() );
-	HMAC_Update( &ctx_prf, sa->idr.buff(), sa->idr.size() );
-	HMAC_Final( &ctx_prf, hash.buff(), NULL );
+	HMAC_Update( ctx_prf, sa->cookies.r, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, sa->cookies.i, ISAKMP_COOKIE_SIZE );
+	HMAC_Update( ctx_prf, sa->hda.buff(), sa->hda.size() );
+	HMAC_Update( ctx_prf, sa->idr.buff(), sa->idr.size() );
+	HMAC_Final( ctx_prf, hash.buff(), NULL );
 
-	HMAC_CTX_cleanup( &ctx_prf );
+	HMAC_CTX_free( ctx_prf );
 
 	log.bin(
 		LLOG_DEBUG,
@@ -2569,14 +2570,14 @@ long _IKED::phase1_gen_natd( IDB_PH1 * ph1 )
 	// hash for remote address
 	//
 
-	EVP_MD_CTX ctx_hash;
-	EVP_DigestInit( &ctx_hash, ph1->evp_hash );
-	EVP_DigestUpdate( &ctx_hash, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
-	EVP_DigestUpdate( &ctx_hash, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
-	EVP_DigestUpdate( &ctx_hash, &ph1->tunnel->saddr_r.saddr4.sin_addr.s_addr, 4 );
-	EVP_DigestUpdate( &ctx_hash, &ph1->tunnel->saddr_r.saddr4.sin_port, 2 );
-	EVP_DigestFinal( &ctx_hash, natd.buff(), NULL );
-	EVP_MD_CTX_cleanup( &ctx_hash );
+	EVP_MD_CTX *ctx_hash;
+	ctx_hash = EVP_MD_CTX_new();
+	EVP_DigestInit( ctx_hash, ph1->evp_hash );
+	EVP_DigestUpdate( ctx_hash, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
+	EVP_DigestUpdate( ctx_hash, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
+	EVP_DigestUpdate( ctx_hash, &ph1->tunnel->saddr_r.saddr4.sin_addr.s_addr, 4 );
+	EVP_DigestUpdate( ctx_hash, &ph1->tunnel->saddr_r.saddr4.sin_port, 2 );
+	EVP_DigestFinal( ctx_hash, natd.buff(), NULL );
 
 	ph1->natd_hash_l.add( natd );
 
@@ -2585,13 +2586,13 @@ long _IKED::phase1_gen_natd( IDB_PH1 * ph1 )
 	// hash for local address
 	//
 
-	EVP_DigestInit( &ctx_hash, ph1->evp_hash );
-	EVP_DigestUpdate( &ctx_hash, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
-	EVP_DigestUpdate( &ctx_hash, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
-	EVP_DigestUpdate( &ctx_hash, &ph1->tunnel->saddr_l.saddr4.sin_addr.s_addr, 4 );
-	EVP_DigestUpdate( &ctx_hash, &ph1->tunnel->saddr_l.saddr4.sin_port, 2 );
-	EVP_DigestFinal( &ctx_hash, natd.buff(), NULL );
-	EVP_MD_CTX_cleanup( &ctx_hash );
+	EVP_DigestInit( ctx_hash, ph1->evp_hash );
+	EVP_DigestUpdate( ctx_hash, ph1->cookies.i, ISAKMP_COOKIE_SIZE );
+	EVP_DigestUpdate( ctx_hash, ph1->cookies.r, ISAKMP_COOKIE_SIZE );
+	EVP_DigestUpdate( ctx_hash, &ph1->tunnel->saddr_l.saddr4.sin_addr.s_addr, 4 );
+	EVP_DigestUpdate( ctx_hash, &ph1->tunnel->saddr_l.saddr4.sin_port, 2 );
+	EVP_DigestFinal( ctx_hash, natd.buff(), NULL );
+	EVP_MD_CTX_free( ctx_hash );
 
 	ph1->natd_hash_l.add( natd );
 
