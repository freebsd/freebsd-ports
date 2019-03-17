--- sendd/sig_rfc3971.c.orig	2019-02-27 16:25:45 UTC
+++ sendd/sig_rfc3971.c
@@ -49,6 +49,11 @@
 extern struct dlog_desc dbg_cryptox;
 #endif
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#define	EVP_MD_CTX_new(x)	calloc(1, sizeof(EVP_MD_CTX))
+#define	EVP_MD_CTX_free(x)	free(x)
+#endif
+
 static void *
 load_privkey(const char *f)
 {
@@ -84,7 +89,7 @@ free_privkey(void *k)
 static uint8_t *
 sign(struct iovec *iov, int iovlen, int *slen, void *priv /* EVP_PKEY */)
 {
-	EVP_MD_CTX ctx[1];
+	EVP_MD_CTX *ctx;
 	uint8_t *sig = NULL;
 	DEFINE_TIMESTAMP_VARS();
 	int i;
@@ -93,9 +98,15 @@ sign(struct iovec *iov, int iovlen, int *slen, void *p
 		DBG(&dbg_snd, "private key not set");
 		return (NULL);
 	}
+	ctx = EVP_MD_CTX_new();
+	if (ctx == NULL) {
+		DBG(&dbg_snd, "EVP_MD_CTX_new() failed");
+		return (NULL);
+	}
 
 	if ((*slen = EVP_PKEY_size(priv)) == 0) {
 		DBG(&dbg_snd, "EVP_PKEY_size() returned 0");
+		EVP_MD_CTX_free(ctx);
 		return (NULL);
 	}
 
@@ -104,6 +115,7 @@ sign(struct iovec *iov, int iovlen, int *slen, void *p
 	EVP_MD_CTX_init(ctx);
 	if (EVP_SignInit(ctx, EVP_sha1()) != 1) {
 		snd_ssl_err(__FUNCTION__, "EVP_SignInit: ");
+		EVP_MD_CTX_free(ctx);
 		return (NULL);
 	}
 
@@ -136,7 +148,10 @@ sign(struct iovec *iov, int iovlen, int *slen, void *p
 	DBG_HEXDUMP(&dbg_cryptox, "sig:", sig, *slen);
 
 done:
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	EVP_MD_CTX_cleanup(ctx);
+#endif
+	EVP_MD_CTX_free(ctx);
 	return (sig);
 }
 
@@ -144,7 +159,7 @@ static int
 ver(struct iovec *iov, int iovlen, uint8_t *key, int klen, uint8_t *sig,
     int slen)
 {
-	EVP_MD_CTX ctx[1];
+	EVP_MD_CTX *ctx;
 	EVP_PKEY *pub;
 	int rv = -1;
 	int i, real_slen, min_bits;
@@ -157,11 +172,17 @@ ver(struct iovec *iov, int iovlen, uint8_t *key, int k
 		DBG(&dbg_snd, "could not d2i key");
 		return (-1);
 	}
+	ctx = EVP_MD_CTX_new();
+	if (ctx == NULL) {
+		DBG(&dbg_snd, "EVP_MD_CTX_new() failed");
+		return (NULL);
+	}
 
 	min_bits = snd_conf_get_int(snd_min_key_bits);
 	if (EVP_PKEY_bits(pub) < min_bits) {
 		DBG(&dbg_snd, "Peer key too weak: %d bits (configured "
 		    "minimum: %d)", EVP_PKEY_bits(pub), min_bits);
+		EVP_MD_CTX_free(ctx);
 		return (-1);
 	}
 
@@ -171,6 +192,7 @@ ver(struct iovec *iov, int iovlen, uint8_t *key, int k
 	} else if (real_slen > slen) {
 		DBG(&dbg_snd, "real sig len (%d) > given sig len (%d)",
 		    real_slen, slen);
+		EVP_MD_CTX_free(ctx);
 		return (-1);
 	}
 	TIMESTAMP_START();
@@ -178,6 +200,7 @@ ver(struct iovec *iov, int iovlen, uint8_t *key, int k
 	EVP_MD_CTX_init(ctx);
 	if (EVP_VerifyInit(ctx, EVP_sha1()) != 1) {
 		snd_ssl_err(__FUNCTION__, "EVP_VerifyInit: ");
+		EVP_MD_CTX_free(ctx);
 		return (-1);
 	}
 
@@ -204,7 +227,10 @@ ver(struct iovec *iov, int iovlen, uint8_t *key, int k
 	TIMESTAMP_END("rfc3971");
 
 done:
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	EVP_MD_CTX_cleanup(ctx);
+#endif
+	EVP_MD_CTX_free(ctx);
 	return (rv);
 }
 
