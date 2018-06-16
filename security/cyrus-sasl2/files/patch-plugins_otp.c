--- plugins/otp.c.orig	2018-02-14 13:16:37 UTC
+++ plugins/otp.c
@@ -98,6 +98,28 @@ static algorithm_option_t algorithm_opti
     {NULL,	0,	NULL}
 };
 
+static EVP_MD_CTX *_plug_EVP_MD_CTX_new(const sasl_utils_t *utils)
+{
+    utils->log(NULL, SASL_LOG_DEBUG, "_plug_EVP_MD_CTX_new()");
+
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    return EVP_MD_CTX_new();
+#else
+    return utils->malloc(sizeof(EVP_MD_CTX));
+#endif    
+}
+
+static void _plug_EVP_MD_CTX_free(EVP_MD_CTX *ctx, const sasl_utils_t *utils)
+{
+    utils->log(NULL, SASL_LOG_DEBUG, "_plug_EVP_MD_CTX_free()");
+
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    EVP_MD_CTX_free(ctx);
+#else
+    utils->free(ctx);
+#endif    
+}
+
 /* Convert the binary data into ASCII hex */
 void bin2hex(unsigned char *bin, int binlen, char *hex)
 {
@@ -118,17 +140,16 @@ void bin2hex(unsigned char *bin, int bin
  * swabbing bytes if necessary.
  */
 static void otp_hash(const EVP_MD *md, char *in, size_t inlen,
-		     unsigned char *out, int swab)
+		     unsigned char *out, int swab, EVP_MD_CTX *mdctx)
 {
-    EVP_MD_CTX mdctx;
     char hash[EVP_MAX_MD_SIZE];
     unsigned int i;
     int j;
     unsigned hashlen;
     
-    EVP_DigestInit(&mdctx, md);
-    EVP_DigestUpdate(&mdctx, in, inlen);
-    EVP_DigestFinal(&mdctx, hash, &hashlen);
+    EVP_DigestInit(mdctx, md);
+    EVP_DigestUpdate(mdctx, in, inlen);
+    EVP_DigestFinal(mdctx, hash, &hashlen);
     
     /* Fold the result into 64 bits */
     for (i = OTP_HASH_SIZE; i < hashlen; i++) {
@@ -151,31 +172,42 @@ static int generate_otp(const sasl_utils
 			char *secret, char *otp)
 {
     const EVP_MD *md;
-    char *key;
+    EVP_MD_CTX *mdctx = NULL;
+    char *key = NULL;
+    int r = SASL_OK;
     
     if (!(md = EVP_get_digestbyname(alg->evp_name))) {
 	utils->seterror(utils->conn, 0,
 			"OTP algorithm %s is not available", alg->evp_name);
 	return SASL_FAIL;
     }
-    
+
+    if ((mdctx = _plug_EVP_MD_CTX_new(utils)) == NULL) {
+	SETERROR(utils, "cannot allocate MD CTX");
+	r = SASL_NOMEM;
+        goto done;
+    }    
+
     if ((key = utils->malloc(strlen(seed) + strlen(secret) + 1)) == NULL) {
 	SETERROR(utils, "cannot allocate OTP key");
-	return SASL_NOMEM;
+        r = SASL_NOMEM;
+        goto done;
     }
     
     /* initial step */
     strcpy(key, seed);
     strcat(key, secret);
-    otp_hash(md, key, strlen(key), otp, alg->swab);
+    otp_hash(md, key, strlen(key), otp, alg->swab, mdctx);
     
     /* computation step */
     while (seq-- > 0)
-	otp_hash(md, otp, OTP_HASH_SIZE, otp, alg->swab);
-    
-    utils->free(key);
+	otp_hash(md, otp, OTP_HASH_SIZE, otp, alg->swab, mdctx);
+
+ done:
+    if (key) utils->free(key);
+    if (mdctx) _plug_EVP_MD_CTX_free(mdctx, utils);
     
-    return SASL_OK;
+    return r;
 }
 
 static int parse_challenge(const sasl_utils_t *utils,
@@ -695,7 +727,8 @@ static int strptrcasecmp(const void *arg
 
 /* Convert the 6 words into binary data */
 static int word2bin(const sasl_utils_t *utils,
-		    char *words, unsigned char *bin, const EVP_MD *md)
+		    char *words, unsigned char *bin, const EVP_MD *md,
+                    EVP_MD_CTX *mdctx)
 {
     int i, j;
     char *c, *word, buf[OTP_RESPONSE_MAX+1];
@@ -754,13 +787,12 @@ static int word2bin(const sasl_utils_t *
 	
 	/* alternate dictionary */
 	if (alt_dict) {
-	    EVP_MD_CTX mdctx;
 	    char hash[EVP_MAX_MD_SIZE];
 	    int hashlen;
 	    
-	    EVP_DigestInit(&mdctx, md);
-	    EVP_DigestUpdate(&mdctx, word, strlen(word));
-	    EVP_DigestFinal(&mdctx, hash, &hashlen);
+	    EVP_DigestInit(mdctx, md);
+	    EVP_DigestUpdate(mdctx, word, strlen(word));
+	    EVP_DigestFinal(mdctx, hash, &hashlen);
 	    
 	    /* use lowest 11 bits */
 	    x = ((hash[hashlen-2] & 0x7) << 8) | hash[hashlen-1];
@@ -804,6 +836,7 @@ static int verify_response(server_contex
 			   char *response)
 {
     const EVP_MD *md;
+    EVP_MD_CTX *mdctx = NULL;
     char *c;
     int do_init = 0;
     unsigned char cur_otp[OTP_HASH_SIZE], prev_otp[OTP_HASH_SIZE];
@@ -817,6 +850,11 @@ static int verify_response(server_contex
 	return SASL_FAIL;
     }
     
+    if ((mdctx = _plug_EVP_MD_CTX_new(utils)) == NULL) {
+	SETERROR(utils, "cannot allocate MD CTX");
+	return SASL_NOMEM;
+    }
+    
     /* eat leading whitespace */
     c = response;
     while (isspace((int) *c)) c++;
@@ -826,7 +864,7 @@ static int verify_response(server_contex
 	    r = hex2bin(c+strlen(OTP_HEX_TYPE), cur_otp, OTP_HASH_SIZE);
 	}
 	else if (!strncasecmp(c, OTP_WORD_TYPE, strlen(OTP_WORD_TYPE))) {
-	    r = word2bin(utils, c+strlen(OTP_WORD_TYPE), cur_otp, md);
+	    r = word2bin(utils, c+strlen(OTP_WORD_TYPE), cur_otp, md, mdctx);
 	}
 	else if (!strncasecmp(c, OTP_INIT_HEX_TYPE,
 			      strlen(OTP_INIT_HEX_TYPE))) {
@@ -836,7 +874,7 @@ static int verify_response(server_contex
 	else if (!strncasecmp(c, OTP_INIT_WORD_TYPE,
 			      strlen(OTP_INIT_WORD_TYPE))) {
 	    do_init = 1;
-	    r = word2bin(utils, c+strlen(OTP_INIT_WORD_TYPE), cur_otp, md);
+	    r = word2bin(utils, c+strlen(OTP_INIT_WORD_TYPE), cur_otp, md, mdctx);
 	}
 	else {
 	    SETERROR(utils, "unknown OTP extended response type");
@@ -852,7 +890,8 @@ static int verify_response(server_contex
     
     if (r == SASL_OK) {
 	/* do one more hash (previous otp) and compare to stored otp */
-	otp_hash(md, cur_otp, OTP_HASH_SIZE, prev_otp, text->alg->swab);
+	otp_hash(md, cur_otp, OTP_HASH_SIZE, 
+		prev_otp, text->alg->swab, mdctx);
 	
 	if (!memcmp(prev_otp, text->otp, OTP_HASH_SIZE)) {
 	    /* update the secret with this seq/otp */
@@ -881,23 +920,28 @@ static int verify_response(server_contex
 		*new_resp++ = '\0';
 	}
 	
-	if (!(new_chal && new_resp))
-	    return SASL_BADAUTH;
+	if (!(new_chal && new_resp)) {
+	    r = SASL_BADAUTH;
+            goto done;
+        }
 	
 	if ((r = parse_challenge(utils, new_chal, &alg, &seq, seed, 1))
 	    != SASL_OK) {
-	    return r;
+            goto done;
 	}
 	
-	if (seq < 1 || !strcasecmp(seed, text->seed))
-	    return SASL_BADAUTH;
+	if (seq < 1 || !strcasecmp(seed, text->seed)) {
+	    r = SASL_BADAUTH;
+            goto done;
+        }
 	
 	/* find the MDA */
 	if (!(md = EVP_get_digestbyname(alg->evp_name))) {
 	    utils->seterror(utils->conn, 0,
 			    "OTP algorithm %s is not available",
 			    alg->evp_name);
-	    return SASL_BADAUTH;
+	    r = SASL_BADAUTH;
+            goto done;
 	}
 	
 	if (!strncasecmp(c, OTP_INIT_HEX_TYPE, strlen(OTP_INIT_HEX_TYPE))) {
@@ -905,7 +949,7 @@ static int verify_response(server_contex
 	}
 	else if (!strncasecmp(c, OTP_INIT_WORD_TYPE,
 			      strlen(OTP_INIT_WORD_TYPE))) {
-	    r = word2bin(utils, new_resp, new_otp, md);
+	    r = word2bin(utils, new_resp, new_otp, md, mdctx);
 	}
 	
 	if (r == SASL_OK) {
@@ -916,7 +960,10 @@ static int verify_response(server_contex
 	    memcpy(text->otp, new_otp, OTP_HASH_SIZE);
 	}
     }
-    
+
+  done:
+    if (mdctx) _plug_EVP_MD_CTX_free(mdctx, utils);
+
     return r;
 }
 
