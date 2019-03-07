--- encfs_fmt_plug.c.orig	2014-11-11 14:41:25 UTC
+++ encfs_fmt_plug.c
@@ -90,25 +90,16 @@ static struct fmt_tests encfs_tests[] = {
 static void setIVec( unsigned char *ivec, uint64_t seed,
         unsigned char *key)
 {
-	unsigned char md[EVP_MAX_MD_SIZE];
-	unsigned int mdLen = EVP_MAX_MD_SIZE;
+	unsigned char iv_and_seed[MAX_IVLENGTH+8];
 	int i;
-	HMAC_CTX mac_ctx;
 
-	memcpy( ivec, &key[cur_salt->keySize], cur_salt->ivLength );
+	// combine ivec and seed with HMAC
+	memcpy(iv_and_seed, &key[cur_salt->keySize], cur_salt->ivLength);
 	for(i=0; i<8; ++i) {
-		md[i] = (unsigned char)(seed & 0xff);
+		iv_and_seed[i+cur_salt->ivLength] = (unsigned char)(seed & 0xff);
 		seed >>= 8;
 	}
-	// combine ivec and seed with HMAC
-	HMAC_CTX_init(&mac_ctx);
-	HMAC_Init_ex( &mac_ctx, key, cur_salt->keySize, EVP_sha1(), 0 );
-	HMAC_Init_ex( &mac_ctx, 0, 0, 0, 0 );
-	HMAC_Update( &mac_ctx, ivec, cur_salt->ivLength );
-	HMAC_Update( &mac_ctx, md, 8 );
-	HMAC_Final( &mac_ctx, md, &mdLen );
-	HMAC_CTX_cleanup(&mac_ctx);
-	memcpy( ivec, md, cur_salt->ivLength );
+	hmac_sha1(key, cur_salt->keySize, iv_and_seed, cur_salt->ivLength+8, ivec, cur_salt->ivLength);
 }
 
 
@@ -144,33 +135,28 @@ static void flipBytes(unsigned char *buf, int size)
 static uint64_t _checksum_64(unsigned char *key,
 		const unsigned char *data, int dataLen, uint64_t *chainedIV)
 {
-	unsigned char md[EVP_MAX_MD_SIZE];
+	unsigned char DataIV[128+8];	// max data len is 128
+	unsigned char md[20];
 	unsigned int mdLen = EVP_MAX_MD_SIZE;
 	int i;
 	unsigned char h[8] = {0,0,0,0,0,0,0,0};
 	uint64_t value;
-	HMAC_CTX mac_ctx;
 
-	HMAC_CTX_init(&mac_ctx);
-	HMAC_Init_ex( &mac_ctx, key, cur_salt->keySize, EVP_sha1(), 0 );
-	HMAC_Init_ex( &mac_ctx, 0, 0, 0, 0 );
-	HMAC_Update( &mac_ctx, data, dataLen );
+	memcpy(DataIV, data, dataLen);
 	if(chainedIV)
 	{
 	  // toss in the chained IV as well
 		uint64_t tmp = *chainedIV;
 		unsigned char h[8];
 		for(i=0; i<8; ++i) {
-			h[i] = tmp & 0xff;
+			h[i] = DataIV[dataLen++] = (tmp & 0xff);
 			tmp >>= 8;
 		}
-		HMAC_Update( &mac_ctx, h, 8 );
 	}
-	HMAC_Final( &mac_ctx, md, &mdLen );
-	HMAC_CTX_cleanup(&mac_ctx);
+	hmac_sha1(key, cur_salt->keySize, DataIV, dataLen, md, 20);
 
 	// chop this down to a 64bit value..
-	for(i=0; i < (mdLen - 1); ++i)
+	for(i=0; i < 19; ++i)
 		h[i%8] ^= (unsigned char)(md[i]);
 
 	value = (uint64_t)h[0];
@@ -202,26 +188,26 @@ static int streamDecode(unsigned char *buf, int size,
 {
 	unsigned char ivec[ MAX_IVLENGTH ];
 	int dstLen=0, tmpLen=0;
-	EVP_CIPHER_CTX stream_dec;
+	EVP_CIPHER_CTX *stream_dec = EVP_CIPHER_CTX_new();
 
 	setIVec( ivec, iv64 + 1, key);
-	EVP_CIPHER_CTX_init(&stream_dec);
-	EVP_DecryptInit_ex( &stream_dec, cur_salt->streamCipher, NULL, NULL, NULL);
-	EVP_CIPHER_CTX_set_key_length( &stream_dec, cur_salt->keySize );
-	EVP_CIPHER_CTX_set_padding( &stream_dec, 0 );
-	EVP_DecryptInit_ex( &stream_dec, NULL, NULL, key, NULL);
+	EVP_CIPHER_CTX_init(stream_dec);
+	EVP_DecryptInit_ex( stream_dec, cur_salt->streamCipher, NULL, NULL, NULL);
+	EVP_CIPHER_CTX_set_key_length( stream_dec, cur_salt->keySize );
+	EVP_CIPHER_CTX_set_padding( stream_dec, 0 );
+	EVP_DecryptInit_ex( stream_dec, NULL, NULL, key, NULL);
 
-	EVP_DecryptInit_ex( &stream_dec, NULL, NULL, NULL, ivec);
-	EVP_DecryptUpdate( &stream_dec, buf, &dstLen, buf, size );
-	EVP_DecryptFinal_ex( &stream_dec, buf+dstLen, &tmpLen );
+	EVP_DecryptInit_ex( stream_dec, NULL, NULL, NULL, ivec);
+	EVP_DecryptUpdate( stream_dec, buf, &dstLen, buf, size );
+	EVP_DecryptFinal_ex( stream_dec, buf+dstLen, &tmpLen );
 	unshuffleBytes( buf, size );
 	flipBytes( buf, size );
 
 	setIVec( ivec, iv64, key );
-	EVP_DecryptInit_ex( &stream_dec, NULL, NULL, NULL, ivec);
-	EVP_DecryptUpdate( &stream_dec, buf, &dstLen, buf, size );
-	EVP_DecryptFinal_ex( &stream_dec, buf+dstLen, &tmpLen );
-	EVP_CIPHER_CTX_cleanup(&stream_dec);
+	EVP_DecryptInit_ex( stream_dec, NULL, NULL, NULL, ivec);
+	EVP_DecryptUpdate( stream_dec, buf, &dstLen, buf, size );
+	EVP_DecryptFinal_ex( stream_dec, buf+dstLen, &tmpLen );
+	EVP_CIPHER_CTX_cleanup(stream_dec);
 
 	unshuffleBytes( buf, size );
 	dstLen += tmpLen;
