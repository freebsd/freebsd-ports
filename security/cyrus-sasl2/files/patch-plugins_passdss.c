--- plugins/passdss.c.orig	2012-01-27 23:31:36 UTC
+++ plugins/passdss.c
@@ -71,6 +71,9 @@
 #include <openssl/sha.h>
 #include <openssl/dsa.h>
 
+/* for legacy libcrypto support */
+#include "crypto-compat.h"
+
 #include <sasl.h>
 #define MD5_H  /* suppress internal MD5 */
 #include <saslplug.h>
@@ -110,23 +113,23 @@ typedef struct context {
     const sasl_utils_t *utils;
     
     /* per-step mem management */
-    char *out_buf;
+    unsigned char *out_buf;
     unsigned out_buf_len;
 
     /* security layer foo */
     unsigned char secmask;	/* bitmask of enabled security layers */
     unsigned char padding[EVP_MAX_BLOCK_LENGTH];  /* block of NULs */
 
-    HMAC_CTX hmac_send_ctx;
-    HMAC_CTX hmac_recv_ctx;
+    HMAC_CTX *hmac_send_ctx;
+    HMAC_CTX *hmac_recv_ctx;
 
     unsigned char send_integrity_key[4 + EVP_MAX_MD_SIZE]; /* +4 for pktnum */
     unsigned char recv_integrity_key[4 + EVP_MAX_MD_SIZE]; /* +4 for pktnum */
     unsigned char *cs_integrity_key;  /* ptr to bare key in send/recv key */
     unsigned char *sc_integrity_key;  /* ptr to bare key in send/recv key */
 
-    EVP_CIPHER_CTX cipher_enc_ctx;
-    EVP_CIPHER_CTX cipher_dec_ctx;
+    EVP_CIPHER_CTX *cipher_enc_ctx;
+    EVP_CIPHER_CTX *cipher_dec_ctx;
     unsigned blk_siz;
     
     unsigned char cs_encryption_iv[EVP_MAX_MD_SIZE];
@@ -139,7 +142,7 @@ typedef struct context {
     uint32_t pktnum_in;
     
     /* for encoding/decoding mem management */
-    char           *encode_buf, *decode_buf, *decode_pkt_buf;
+    unsigned char  *encode_buf, *decode_buf, *decode_pkt_buf;
     unsigned       encode_buf_len, decode_buf_len, decode_pkt_buf_len;
     
     /* layers buffering */
@@ -171,7 +174,7 @@ static int passdss_encode(void *context,
 	inputlen += invec[i].iov_len;
 
     /* allocate a buffer for the output */
-    ret = _plug_buf_alloc(text->utils, &text->encode_buf,
+    ret = _plug_buf_alloc(text->utils, (char **) &text->encode_buf,
 			  &text->encode_buf_len,
 			  4 +				/* length */
 			  inputlen +			/* content */
@@ -186,19 +189,19 @@ static int passdss_encode(void *context,
     memcpy(text->send_integrity_key, &tmpnum, 4);
 
     /* key the HMAC */
-    HMAC_Init_ex(&text->hmac_send_ctx, text->send_integrity_key,
+    HMAC_Init_ex(text->hmac_send_ctx, text->send_integrity_key,
 		 4+SHA_DIGEST_LENGTH, EVP_sha1(), NULL);
 
     /* operate on each iovec */
     for (i = 0; i < numiov; i++) {
 	/* hash the content */
-	HMAC_Update(&text->hmac_send_ctx, invec[i].iov_base, invec[i].iov_len);
+	HMAC_Update(text->hmac_send_ctx, invec[i].iov_base, invec[i].iov_len);
 
 	if (text->secmask & PRIVACY_LAYER_FLAG) {
-	    unsigned enclen;
+	    int enclen;
 
 	    /* encrypt the data into the output buffer */
-	    EVP_EncryptUpdate(&text->cipher_enc_ctx,
+	    EVP_EncryptUpdate(text->cipher_enc_ctx,
 			      text->encode_buf + *outputlen, &enclen,
 			      invec[i].iov_base, invec[i].iov_len);
 	    *outputlen += enclen;
@@ -212,14 +215,14 @@ static int passdss_encode(void *context,
     }
 
     /* calculate the HMAC */
-    HMAC_Final(&text->hmac_send_ctx, hmac, &hmaclen);
+    HMAC_Final(text->hmac_send_ctx, hmac, &hmaclen);
 
     if (text->secmask & PRIVACY_LAYER_FLAG) {
-	unsigned enclen;
+	int enclen;
 	unsigned char padlen;
 
 	/* encrypt the HMAC into the output buffer */
-	EVP_EncryptUpdate(&text->cipher_enc_ctx,
+	EVP_EncryptUpdate(text->cipher_enc_ctx,
 			  text->encode_buf + *outputlen, &enclen,
 			  hmac, hmaclen);
 	*outputlen += enclen;
@@ -227,17 +230,17 @@ static int passdss_encode(void *context,
 	/* pad output buffer to multiple of blk_siz
 	   with padlen-1 as last octet */
 	padlen = text->blk_siz - ((inputlen + hmaclen) % text->blk_siz) - 1;
-	EVP_EncryptUpdate(&text->cipher_enc_ctx,
+	EVP_EncryptUpdate(text->cipher_enc_ctx,
 			  text->encode_buf + *outputlen, &enclen,
 			  text->padding, padlen);
 	*outputlen += enclen;
-	EVP_EncryptUpdate(&text->cipher_enc_ctx,
+	EVP_EncryptUpdate(text->cipher_enc_ctx,
 			  text->encode_buf + *outputlen, &enclen,
 			  &padlen, 1);
 	*outputlen += enclen;
 
 	/* encrypt the last block of data into the output buffer */
-	EVP_EncryptFinal_ex(&text->cipher_enc_ctx,
+	EVP_EncryptFinal_ex(text->cipher_enc_ctx,
 			    text->encode_buf + *outputlen, &enclen);
 	*outputlen += enclen;
     }
@@ -252,7 +255,7 @@ static int passdss_encode(void *context,
     tmpnum = htonl(tmpnum);
     memcpy(text->encode_buf, &tmpnum, 4);
 
-    *output = text->encode_buf;
+    *output = (char *) text->encode_buf;
     
     return SASL_OK;
 }
@@ -271,25 +274,25 @@ static int passdss_decode_packet(void *c
     int ret;
 
     if (text->secmask & PRIVACY_LAYER_FLAG) {
-	unsigned declen, padlen;
+	int declen, padlen;
 
 	/* allocate a buffer for the output */
-	ret = _plug_buf_alloc(text->utils, &(text->decode_pkt_buf),
+	ret = _plug_buf_alloc(text->utils, (char **) &(text->decode_pkt_buf),
 			      &(text->decode_pkt_buf_len), inputlen);
 	if (ret != SASL_OK) return ret;
 
 	/* decrypt the data into the output buffer */
-	ret = EVP_DecryptUpdate(&text->cipher_dec_ctx,
+	ret = EVP_DecryptUpdate(text->cipher_dec_ctx,
 				text->decode_pkt_buf, &declen,
-				(char *) input, inputlen);
+				(unsigned char *) input, inputlen);
 	if (ret)
-	    EVP_DecryptFinal_ex(&text->cipher_dec_ctx,  /* should be no output */
+	    EVP_DecryptFinal_ex(text->cipher_dec_ctx,  /* should be no output */
 				text->decode_pkt_buf + declen, &declen);
 	if (!ret) {
 	    SETERROR(text->utils, "Error decrypting input");
 	    return SASL_BADPROT;
 	}
-	input = text->decode_pkt_buf;
+	input = (char *) text->decode_pkt_buf;
 
 	/* trim padding */
 	padlen = text->decode_pkt_buf[inputlen - 1] + 1;
@@ -305,7 +308,7 @@ static int passdss_decode_packet(void *c
 
     /* calculate the HMAC */
     HMAC(EVP_sha1(), text->recv_integrity_key, 4+SHA_DIGEST_LENGTH,
-	 input, inputlen, hmac, &hmaclen);
+	 (unsigned char *) input, inputlen, hmac, &hmaclen);
 
     /* verify HMAC */
     if (memcmp(hmac, input+inputlen, hmaclen)) {
@@ -326,12 +329,12 @@ static int passdss_decode(void *context,
 {
     context_t *text = (context_t *) context;
     int ret;
-    
+
     ret = _plug_decode(&text->decode_context, input, inputlen,
-		       &text->decode_buf, &text->decode_buf_len, outputlen,
-		       passdss_decode_packet, text);
+		       (char **) &text->decode_buf, &text->decode_buf_len,
+                       outputlen, passdss_decode_packet, text);
     
-    *output = text->decode_buf;
+    *output = (const char *) text->decode_buf;
     
     return ret;
 }
@@ -342,7 +345,8 @@ static int passdss_decode(void *context,
 /*
  * Create/append to a PASSDSS buffer from the data specified by the fmt string.
  */
-static int MakeBuffer(const sasl_utils_t *utils, char **buf, unsigned offset,
+static int MakeBuffer(const sasl_utils_t *utils,
+                      unsigned char **buf, unsigned offset,
 		      unsigned *buflen, unsigned *outlen, const char *fmt, ...)
 {
     va_list ap;
@@ -425,10 +429,10 @@ static int MakeBuffer(const sasl_utils_t
     }
     va_end(ap);
 
-    r = _plug_buf_alloc(utils, buf, buflen, alloclen);
+    r = _plug_buf_alloc(utils, (char **) buf, buflen, alloclen);
     if (r != SASL_OK) return r;
 
-    out = *buf + offset;
+    out = (char *) *buf + offset;
 
     /* second pass to fill buffer */
     va_start(ap, fmt);
@@ -463,7 +467,7 @@ static int MakeBuffer(const sasl_utils_t
 	case 'm':
 	    /* MPI */
 	    mpi = va_arg(ap, BIGNUM *);
-	    len = BN_bn2bin(mpi, out+4);
+	    len = BN_bn2bin(mpi, (unsigned char *) out+4);
 	    nl = htonl(len);
 	    memcpy(out, &nl, 4);	/* add 4 byte len (network order) */
 	    out += len + 4;
@@ -515,7 +519,7 @@ static int MakeBuffer(const sasl_utils_t
   done:
     va_end(ap);
 
-    *outlen = out - *buf;
+    *outlen = out - (char *) *buf;
 
     return r;
 }
@@ -600,8 +604,8 @@ static int UnBuffer(const sasl_utils_t *
 	    
 	    if (mpi) {
 		if (!*mpi) *mpi = BN_new();
-		BN_init(*mpi);
-		BN_bin2bn(buf, len, *mpi);
+		BN_clear(*mpi);
+		BN_bin2bn((unsigned char *) buf, len, *mpi);
 	    }
 	    break;
 
@@ -716,16 +720,16 @@ static int UnBuffer(const sasl_utils_t *
 }
 
 #define DOHASH(out, in1, len1, in2, len2, in3, len3)	\
-    EVP_DigestInit(&mdctx, EVP_sha1());			\
-    EVP_DigestUpdate(&mdctx, in1, len1);		\
-    EVP_DigestUpdate(&mdctx, in2, len2);		\
-    EVP_DigestUpdate(&mdctx, in3, len3);		\
-    EVP_DigestFinal(&mdctx, out, NULL)
+    EVP_DigestInit(mdctx, EVP_sha1());			\
+    EVP_DigestUpdate(mdctx, in1, len1);			\
+    EVP_DigestUpdate(mdctx, in2, len2);			\
+    EVP_DigestUpdate(mdctx, in3, len3);			\
+    EVP_DigestFinal(mdctx, out, NULL)
 
-void CalcLayerParams(context_t *text, char *K, unsigned Klen,
-		     char *hash, unsigned hashlen)
+void CalcLayerParams(context_t *text, unsigned char *K, unsigned Klen,
+		     unsigned char *hash, unsigned hashlen)
 {
-    EVP_MD_CTX mdctx;
+    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
 
     DOHASH(text->cs_encryption_iv, K, Klen, "A", 1, hash, hashlen);
     DOHASH(text->sc_encryption_iv, K, Klen, "B", 1, hash, hashlen);
@@ -737,6 +741,8 @@ void CalcLayerParams(context_t *text, ch
 	   text->sc_encryption_key, hashlen);
     DOHASH(text->cs_integrity_key, K, Klen, "E", 1, hash, hashlen);
     DOHASH(text->sc_integrity_key, K, Klen, "F", 1, hash, hashlen);
+
+    EVP_MD_CTX_free(mdctx);
 }
 
 /*
@@ -755,11 +761,11 @@ static void passdss_common_mech_dispose(
 
     if (text->dh)		DH_free(text->dh);
 
-    HMAC_CTX_cleanup(&text->hmac_send_ctx);
-    HMAC_CTX_cleanup(&text->hmac_recv_ctx);
+    HMAC_CTX_free(text->hmac_send_ctx);
+    HMAC_CTX_free(text->hmac_recv_ctx);
 
-    EVP_CIPHER_CTX_cleanup(&text->cipher_enc_ctx);
-    EVP_CIPHER_CTX_cleanup(&text->cipher_dec_ctx);
+    EVP_CIPHER_CTX_free(text->cipher_enc_ctx);
+    EVP_CIPHER_CTX_free(text->cipher_dec_ctx);
     
     _plug_decode_free(&text->decode_context);
 
@@ -809,15 +815,17 @@ passdss_server_mech_step1(context_t *tex
 			  unsigned *serveroutlen,
 			  sasl_out_params_t *oparams __attribute__((unused)))
 {
-    BIGNUM *X = NULL;
+    BIGNUM *X = NULL, *dh_p = NULL, *dh_g = NULL;
     DSA *dsa = NULL;
+    const BIGNUM *dsa_p, *dsa_q, *dsa_g, *dsa_pub_key, *dh_pub_key;
     unsigned char *K = NULL;
     unsigned Klen, hashlen;
     int need, musthave;
-    EVP_MD_CTX mdctx;
+    EVP_MD_CTX *mdctx;
     unsigned char hash[EVP_MAX_MD_SIZE];
     DSA_SIG *sig = NULL;
-    int result;
+    const BIGNUM *sig_r, *sig_s;
+    int r = 0, result;
     
     /* Expect:
      *
@@ -835,8 +843,18 @@ passdss_server_mech_step1(context_t *tex
     }
 
     /* Fetch DSA (XXX create one for now) */
-    dsa = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);
+    dsa = DSA_new();
     if (!dsa) {
+	params->utils->log(NULL,
+                           SASL_LOG_ERR, "Error creating DSA\n");
+	result = SASL_FAIL;
+	goto cleanup;
+    }
+
+    r = DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, NULL);
+    if (!r) {
+	params->utils->log(NULL,
+                           SASL_LOG_ERR, "Error generating DSA parameters\n");
 	result = SASL_FAIL;
 	goto cleanup;
     }
@@ -844,8 +862,9 @@ passdss_server_mech_step1(context_t *tex
 
     /* Create Diffie-Hellman parameters */
     text->dh = DH_new();
-    BN_hex2bn(&text->dh->p, N);
-    BN_hex2bn(&text->dh->g, g);
+    BN_hex2bn(&dh_p, N);
+    BN_hex2bn(&dh_g, g);
+    DH_set0_pqg(text->dh, dh_p, NULL, dh_g);
     DH_generate_key(text->dh);
 
     /* Alloc space for shared secret K as mpint */
@@ -897,10 +916,13 @@ passdss_server_mech_step1(context_t *tex
      */
 
     /* Items (4) - (7) */
+    DSA_get0_pqg(dsa, &dsa_p, &dsa_q, &dsa_g);
+    DSA_get0_key(dsa, &dsa_pub_key, NULL);
+    DH_get0_key(text->dh, &dh_pub_key, NULL);
     result = MakeBuffer(text->utils, &text->out_buf, 0, &text->out_buf_len,
 			serveroutlen, "%5a%s%m%m%m%m%m%1o%3u",
-			"ssh-dss", dsa->p, dsa->q, dsa->g, dsa->pub_key,
-			text->dh->pub_key, &text->secmask,
+			"ssh-dss", dsa_p, dsa_q, dsa_g, dsa_pub_key,
+			dh_pub_key, &text->secmask,
 			(params->props.maxbufsize > 0xFFFFFF) ? 0xFFFFFF :
 			params->props.maxbufsize);
     if (result) {
@@ -909,26 +931,29 @@ passdss_server_mech_step1(context_t *tex
     }
 
     /* Hash (1) - (7) and K */
-    EVP_DigestInit(&mdctx, EVP_sha1());
+    mdctx = EVP_MD_CTX_new();
+    EVP_DigestInit(mdctx, EVP_sha1());
     /* (1) - (3) */
-    EVP_DigestUpdate(&mdctx, clientin, clientinlen);
+    EVP_DigestUpdate(mdctx, clientin, clientinlen);
     /* (4) - (7) */
-    EVP_DigestUpdate(&mdctx, text->out_buf, *serveroutlen);
+    EVP_DigestUpdate(mdctx, text->out_buf, *serveroutlen);
     /* K */
-    EVP_DigestUpdate(&mdctx, K, Klen);
-    EVP_DigestFinal(&mdctx, hash, &hashlen);
+    EVP_DigestUpdate(mdctx, K, Klen);
+    EVP_DigestFinal(mdctx, hash, &hashlen);
+    EVP_MD_CTX_free(mdctx);
 
     /* Calculate security layer params */
     CalcLayerParams(text, K, Klen, hash, hashlen);
 
     /* Start cli-hmac */
-    HMAC_CTX_init(&text->hmac_recv_ctx);
-    HMAC_Init_ex(&text->hmac_recv_ctx, text->cs_integrity_key,
+    text->hmac_recv_ctx = HMAC_CTX_new();
+    HMAC_CTX_reset(text->hmac_recv_ctx);
+    HMAC_Init_ex(text->hmac_recv_ctx, text->cs_integrity_key,
 		 SHA_DIGEST_LENGTH, EVP_sha1(), NULL);
     /* (1) - (3) */
-    HMAC_Update(&text->hmac_recv_ctx, clientin, clientinlen);
+    HMAC_Update(text->hmac_recv_ctx, (unsigned char *) clientin, clientinlen);
     /* (4) - (7) */
-    HMAC_Update(&text->hmac_recv_ctx, text->out_buf, *serveroutlen);
+    HMAC_Update(text->hmac_recv_ctx, text->out_buf, *serveroutlen);
 
     /* Sign the hash */
     sig = DSA_do_sign(hash, hashlen, dsa);
@@ -940,14 +965,15 @@ passdss_server_mech_step1(context_t *tex
     }
 
     /* Item (8) */
+    DSA_SIG_get0(sig, &sig_r, &sig_s);
     result = MakeBuffer(text->utils, &text->out_buf, *serveroutlen,
 			&text->out_buf_len, serveroutlen,
-			"%3a%s%m%m", "ssh-dss", sig->r, sig->s);
+			"%3a%s%m%m", "ssh-dss", sig_r, sig_s);
     if (result) {
 	params->utils->log(NULL, SASL_LOG_ERR, "Error making output buffer\n");
 	goto cleanup;
     }
-    *serverout = text->out_buf;
+    *serverout = (char *) text->out_buf;
 
     text->state = 2;
     result = SASL_CONTINUE;
@@ -971,10 +997,10 @@ passdss_server_mech_step2(context_t *tex
 			  sasl_out_params_t *oparams)
 {
     char *password = NULL;
-    unsigned declen, hmaclen;
+    unsigned hmaclen;
     unsigned char *csecmask, *cli_hmac, hmac[EVP_MAX_MD_SIZE];
     uint32_t cbufsiz;
-    int r, result = SASL_OK;
+    int declen, r, result = SASL_OK;
     
     /* Expect (3DES encrypted):
      *
@@ -985,7 +1011,7 @@ passdss_server_mech_step2(context_t *tex
      */
 
     /* Alloc space for the decrypted input */
-    result = _plug_buf_alloc(text->utils, &text->decode_pkt_buf,
+    result = _plug_buf_alloc(text->utils, (char **) &text->decode_pkt_buf,
 			     &text->decode_pkt_buf_len, clientinlen);
     if (result) {
 	params->utils->log(NULL, SASL_LOG_ERR,
@@ -994,25 +1020,28 @@ passdss_server_mech_step2(context_t *tex
     }
 
     /* Initialize decrypt cipher */
-    EVP_CIPHER_CTX_init(&text->cipher_dec_ctx);
-    EVP_DecryptInit_ex(&text->cipher_dec_ctx, EVP_des_ede3_cbc(), NULL,
+    text->cipher_dec_ctx = EVP_CIPHER_CTX_new();
+    EVP_CIPHER_CTX_init(text->cipher_dec_ctx);
+    EVP_DecryptInit_ex(text->cipher_dec_ctx, EVP_des_ede3_cbc(), NULL,
 		       text->cs_encryption_key, text->cs_encryption_iv);
-    EVP_CIPHER_CTX_set_padding(&text->cipher_dec_ctx, 0);
-    text->blk_siz = EVP_CIPHER_CTX_block_size(&text->cipher_dec_ctx);
+    EVP_CIPHER_CTX_set_padding(text->cipher_dec_ctx, 0);
+    text->blk_siz = EVP_CIPHER_CTX_block_size(text->cipher_dec_ctx);
 
     /* Decrypt the blob */
-    r = EVP_DecryptUpdate(&text->cipher_dec_ctx, text->decode_pkt_buf, &declen,
-			  clientin, clientinlen);
+    r = EVP_DecryptUpdate(text->cipher_dec_ctx,
+                          text->decode_pkt_buf, &declen,
+			  (unsigned char *) clientin, clientinlen);
     if (r)
-	r = EVP_DecryptFinal_ex(&text->cipher_dec_ctx,  /* should be no output */
-				text->decode_pkt_buf + declen, &declen);
+	r = EVP_DecryptFinal_ex(text->cipher_dec_ctx,  /* should be no output */
+				text->decode_pkt_buf + declen,
+                                &declen);
     if (!r) {
 	params->utils->seterror(params->utils->conn, 0, 
 				"Error decrypting input in step 2");
 	result = SASL_BADPROT;
 	goto cleanup;
     }
-    clientin = text->decode_pkt_buf;
+    clientin = (char *) text->decode_pkt_buf;
 
     result = UnBuffer(params->utils, clientin, clientinlen,
 		      "%-1o%3u%s%-*o%*p", &csecmask, &cbufsiz, &password,
@@ -1026,8 +1055,8 @@ passdss_server_mech_step2(context_t *tex
     /* Finish cli-hmac */
     /* (1) - (7) hashed in step 1 */
     /* 1st 4 bytes of (9) */
-    HMAC_Update(&text->hmac_recv_ctx, clientin, 4);
-    HMAC_Final(&text->hmac_recv_ctx, hmac, &hmaclen);
+    HMAC_Update(text->hmac_recv_ctx, (unsigned char *) clientin, 4);
+    HMAC_Final(text->hmac_recv_ctx, hmac, &hmaclen);
 
     /* Verify cli-hmac */
     if (memcmp(cli_hmac, hmac, hmaclen)) {
@@ -1089,16 +1118,18 @@ passdss_server_mech_step2(context_t *tex
 	oparams->decode = &passdss_decode;
 	oparams->maxoutbuf = cbufsiz - 4 - SHA_DIGEST_LENGTH; /* -len -HMAC */
 
-	HMAC_CTX_init(&text->hmac_send_ctx);
+        text->hmac_send_ctx = HMAC_CTX_new();
+	HMAC_CTX_reset(text->hmac_send_ctx);
 
 	if (oparams->mech_ssf > 1) {
 	    oparams->maxoutbuf -= text->blk_siz-1; /* padding */
 
 	    /* Initialize encrypt cipher */
-	    EVP_CIPHER_CTX_init(&text->cipher_enc_ctx);
-	    EVP_EncryptInit_ex(&text->cipher_enc_ctx, EVP_des_ede3_cbc(), NULL,
+            text->cipher_enc_ctx = EVP_CIPHER_CTX_new();
+	    EVP_CIPHER_CTX_init(text->cipher_enc_ctx);
+	    EVP_EncryptInit_ex(text->cipher_enc_ctx, EVP_des_ede3_cbc(), NULL,
 			       text->sc_encryption_key, text->sc_encryption_iv);
-	    EVP_CIPHER_CTX_set_padding(&text->cipher_enc_ctx, 0);
+	    EVP_CIPHER_CTX_set_padding(text->cipher_enc_ctx, 0);
 	}
 
 	_plug_decode_init(&text->decode_context, text->utils,
@@ -1247,6 +1278,8 @@ passdss_client_mech_step1(context_t *tex
     int auth_result = SASL_OK;
     int pass_result = SASL_OK;
     int result;
+    BIGNUM *dh_p = NULL, *dh_g = NULL;
+    const BIGNUM *dh_pub_key;
 
     /* Expect: absolutely nothing */
     if (serverinlen > 0) {
@@ -1334,8 +1367,9 @@ passdss_client_mech_step1(context_t *tex
 
     /* create Diffie-Hellman parameters */
     text->dh = DH_new();
-    BN_hex2bn(&text->dh->p, N);
-    BN_hex2bn(&text->dh->g, g);
+    BN_hex2bn(&dh_p, N);
+    BN_hex2bn(&dh_g, g);
+    DH_set0_pqg(text->dh, dh_p, NULL, dh_g);
     DH_generate_key(text->dh);
 
 
@@ -1346,15 +1380,16 @@ passdss_client_mech_step1(context_t *tex
      * (3) mpint  X 		; Diffie-Hellman parameter X
      */
     
+    DH_get0_key(text->dh, &dh_pub_key, NULL);
     result = MakeBuffer(text->utils, &text->out_buf, 0, &text->out_buf_len,
 			clientoutlen, "%s%s%m",
 			(user && *user) ? (char *) oparams->user : "",
-			(char *) oparams->authid, text->dh->pub_key);
+			(char *) oparams->authid, dh_pub_key);
     if (result) {
 	params->utils->log(NULL, SASL_LOG_ERR, "Error making output buffer\n");
 	goto cleanup;
     }
-    *clientout = text->out_buf;
+    *clientout = (char *) text->out_buf;
     
     text->state = 2;
     result = SASL_CONTINUE;
@@ -1376,15 +1411,16 @@ passdss_client_mech_step2(context_t *tex
 {
     DSA *dsa = DSA_new();
     DSA_SIG *sig = DSA_SIG_new();
-    BIGNUM *Y = NULL;
+    BIGNUM *dsa_p = NULL, *dsa_q = NULL, *dsa_g = NULL, *dsa_pub_key = NULL;
+    BIGNUM *Y = NULL, *sig_r = NULL, *sig_s = NULL;
     uint32_t siglen;
     unsigned char *K = NULL;
-    unsigned Klen, hashlen, enclen;
+    unsigned Klen, hashlen;
     unsigned char *ssecmask;
     uint32_t sbufsiz;
-    EVP_MD_CTX mdctx;
+    EVP_MD_CTX *mdctx;
     unsigned char hash[EVP_MAX_MD_SIZE];
-    int need, musthave;
+    int enclen, need, musthave;
     int result, r;
     
     /* Expect:
@@ -1406,14 +1442,18 @@ passdss_client_mech_step2(context_t *tex
 
     result = UnBuffer(params->utils, serverin, serverinlen,
 		      "%u%3p\7ssh-dss%m%m%m%m%m%-1o%3u%u%3p\7ssh-dss%m%m",
-		      NULL, &dsa->p, &dsa->q, &dsa->g, &dsa->pub_key,
-		      &Y, &ssecmask, &sbufsiz, &siglen, &sig->r, &sig->s);
+		      NULL, &dsa_p, &dsa_q, &dsa_g, &dsa_pub_key,
+		      &Y, &ssecmask, &sbufsiz, &siglen, &sig_r, &sig_s);
     if (result) {
 	params->utils->seterror(params->utils->conn, 0, 
 				"Error UnBuffering input in step 2");
 	goto cleanup;
     }
 
+    DSA_set0_pqg(dsa, dsa_p, dsa_q, dsa_g);
+    DSA_set0_key(dsa, dsa_pub_key, NULL);
+    DSA_SIG_set0(sig, sig_r, sig_s);
+
     /* XXX  Validate server DSA public key */
 
     /* Alloc space for shared secret K as mpint */
@@ -1432,14 +1472,16 @@ passdss_client_mech_step2(context_t *tex
     Klen += 4;
 
     /* Hash (1) - (7) and K */
-    EVP_DigestInit(&mdctx, EVP_sha1());
+    mdctx = EVP_MD_CTX_new();
+    EVP_DigestInit(mdctx, EVP_sha1());
     /* (1) - (3) (output from step 1 still in buffer) */
-    EVP_DigestUpdate(&mdctx, text->out_buf, text->out_buf_len);
+    EVP_DigestUpdate(mdctx, text->out_buf, text->out_buf_len);
     /* (4) - (7) */
-    EVP_DigestUpdate(&mdctx, serverin, serverinlen - siglen - 4);
+    EVP_DigestUpdate(mdctx, serverin, serverinlen - siglen - 4);
     /* K */
-    EVP_DigestUpdate(&mdctx, K, Klen);
-    EVP_DigestFinal(&mdctx, hash, &hashlen);
+    EVP_DigestUpdate(mdctx, K, Klen);
+    EVP_DigestFinal(mdctx, hash, &hashlen);
+    EVP_MD_CTX_free(mdctx);
 
     /* Verify signature on the hash */
     result = DSA_do_verify(hash, hashlen, sig, dsa);
@@ -1455,11 +1497,12 @@ passdss_client_mech_step2(context_t *tex
     CalcLayerParams(text, K, Klen, hash, hashlen);
 
     /* Initialize encrypt cipher */
-    EVP_CIPHER_CTX_init(&text->cipher_enc_ctx);
-    EVP_EncryptInit_ex(&text->cipher_enc_ctx, EVP_des_ede3_cbc(), NULL,
+    text->cipher_enc_ctx = EVP_CIPHER_CTX_new();
+    EVP_CIPHER_CTX_init(text->cipher_enc_ctx);
+    EVP_EncryptInit_ex(text->cipher_enc_ctx, EVP_des_ede3_cbc(), NULL,
 		       text->cs_encryption_key, text->cs_encryption_iv);
-    EVP_CIPHER_CTX_set_padding(&text->cipher_enc_ctx, 0);
-    text->blk_siz = EVP_CIPHER_CTX_block_size(&text->cipher_enc_ctx);
+    EVP_CIPHER_CTX_set_padding(text->cipher_enc_ctx, 0);
+    text->blk_siz = EVP_CIPHER_CTX_block_size(text->cipher_enc_ctx);
 
     /* pick a layer */
     if (params->props.maxbufsize < 32) {
@@ -1490,13 +1533,15 @@ passdss_client_mech_step2(context_t *tex
     }
 
     /* Start cli-hmac */
-    HMAC_CTX_init(&text->hmac_send_ctx);
-    HMAC_Init_ex(&text->hmac_send_ctx, text->cs_integrity_key,
+    text->hmac_send_ctx = HMAC_CTX_new();
+    HMAC_CTX_reset(text->hmac_send_ctx);
+    HMAC_Init_ex(text->hmac_send_ctx, text->cs_integrity_key,
 		 SHA_DIGEST_LENGTH, EVP_sha1(), NULL);
     /* (1) - (3) (output from step 1 still in buffer) */
-    HMAC_Update(&text->hmac_send_ctx, text->out_buf, text->out_buf_len);
+    HMAC_Update(text->hmac_send_ctx, text->out_buf, text->out_buf_len);
     /* (4) - (7) */
-    HMAC_Update(&text->hmac_send_ctx, serverin, serverinlen - siglen - 4);
+    HMAC_Update(text->hmac_send_ctx,
+                (unsigned char *) serverin, serverinlen - siglen - 4);
 
 
     /* Send out (3DES encrypted):
@@ -1520,8 +1565,8 @@ passdss_client_mech_step2(context_t *tex
 
     /* Finish cli-hmac */
     /* 1st 4 bytes of (9) */
-    HMAC_Update(&text->hmac_send_ctx, text->out_buf, 4);
-    HMAC_Final(&text->hmac_send_ctx, hash, &hashlen);
+    HMAC_Update(text->hmac_send_ctx, text->out_buf, 4);
+    HMAC_Final(text->hmac_send_ctx, hash, &hashlen);
 
     /* Add HMAC and pad to fill no more than current block */
     result = MakeBuffer(text->utils, &text->out_buf, *clientoutlen,
@@ -1533,7 +1578,7 @@ passdss_client_mech_step2(context_t *tex
     }
 
     /* Alloc space for the encrypted output */
-    result = _plug_buf_alloc(text->utils, &text->encode_buf,
+    result = _plug_buf_alloc(text->utils, (char **) &text->encode_buf,
 			     &text->encode_buf_len, *clientoutlen);
     if (result) {
 	params->utils->log(NULL, SASL_LOG_ERR,
@@ -1542,19 +1587,20 @@ passdss_client_mech_step2(context_t *tex
     }
 
     /* Encrypt (9) (here we calculate the exact number of full blocks) */
-    r = EVP_EncryptUpdate(&text->cipher_enc_ctx, text->encode_buf,
-			  clientoutlen, text->out_buf,
+    r = EVP_EncryptUpdate(text->cipher_enc_ctx,
+                          text->encode_buf, (int *) clientoutlen, text->out_buf,
 			  text->blk_siz * (*clientoutlen / text->blk_siz));
     if (r)
-	r = EVP_EncryptFinal_ex(&text->cipher_enc_ctx,  /* should be no output */
-				text->encode_buf + *clientoutlen, &enclen);
+	r = EVP_EncryptFinal_ex(text->cipher_enc_ctx,  /* should be no output */
+				text->encode_buf + *clientoutlen,
+                                &enclen);
     if (!r) {
 	params->utils->seterror(params->utils->conn, 0, 
 				"Error encrypting output in step 2");
 	result = SASL_FAIL;
 	goto cleanup;
     }
-    *clientout = text->encode_buf;
+    *clientout = (char *) text->encode_buf;
 
     /* Set oparams */
     oparams->doneflag = 1;
@@ -1565,16 +1611,18 @@ passdss_client_mech_step2(context_t *tex
 	oparams->decode = &passdss_decode;
 	oparams->maxoutbuf = sbufsiz - 4 - SHA_DIGEST_LENGTH; /* -len -HMAC */
 
-	HMAC_CTX_init(&text->hmac_recv_ctx);
+        text->hmac_recv_ctx = HMAC_CTX_new();
+	HMAC_CTX_reset(text->hmac_recv_ctx);
 
 	if (oparams->mech_ssf > 1) {
 	    oparams->maxoutbuf -= text->blk_siz-1; /* padding */
 
 	    /* Initialize decrypt cipher */
-	    EVP_CIPHER_CTX_init(&text->cipher_dec_ctx);
-	    EVP_DecryptInit_ex(&text->cipher_dec_ctx, EVP_des_ede3_cbc(), NULL,
+            text->cipher_dec_ctx = EVP_CIPHER_CTX_new();
+	    EVP_CIPHER_CTX_init(text->cipher_dec_ctx);
+	    EVP_DecryptInit_ex(text->cipher_dec_ctx, EVP_des_ede3_cbc(), NULL,
 			       text->sc_encryption_key, text->sc_encryption_iv);
-	    EVP_CIPHER_CTX_set_padding(&text->cipher_dec_ctx, 0);
+	    EVP_CIPHER_CTX_set_padding(text->cipher_dec_ctx, 0);
 	}
 
 	_plug_decode_init(&text->decode_context, text->utils,
