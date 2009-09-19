--- crypto/engine/eng_cryptodev.c.orig	2004-06-15 13:45:42.000000000 +0200
+++ crypto/engine/eng_cryptodev.c	2009-01-09 19:14:28.000000000 +0100
@@ -32,7 +32,7 @@
 #include <openssl/bn.h>
 
 #if (defined(__unix__) || defined(unix)) && !defined(USG) && \
-	(defined(OpenBSD) || defined(__FreeBSD_version))
+	(defined(OpenBSD) || defined(__FreeBSD__))
 #include <sys/param.h>
 # if (OpenBSD >= 200112) || ((__FreeBSD_version >= 470101 && __FreeBSD_version < 500000) || __FreeBSD_version >= 500041)
 #  define HAVE_CRYPTODEV
@@ -70,14 +70,19 @@
 	int d_fd;
 };
 
+struct dev_crypto_cipher {
+	int	c_id;
+	int	c_nid;
+	int	c_ivmax;
+	int	c_keylen;
+};
+
 static u_int32_t cryptodev_asymfeat = 0;
 
 static int get_asym_dev_crypto(void);
 static int open_dev_crypto(void);
 static int get_dev_crypto(void);
-static int cryptodev_max_iv(int cipher);
-static int cryptodev_key_length_valid(int cipher, int len);
-static int cipher_nid_to_cryptodev(int nid);
+static struct dev_crypto_cipher *cipher_nid_to_cryptodev(int nid);
 static int get_cryptodev_ciphers(const int **cnids);
 static int get_cryptodev_digests(const int **cnids);
 static int cryptodev_usable_ciphers(const int **nids);
@@ -124,15 +129,12 @@
 	{ 0, NULL, NULL, 0 }
 };
 
-static struct {
-	int	id;
-	int	nid;
-	int	ivmax;
-	int	keylen;
-} ciphers[] = {
+static struct dev_crypto_cipher ciphers[] = {
 	{ CRYPTO_DES_CBC,		NID_des_cbc,		8,	 8, },
 	{ CRYPTO_3DES_CBC,		NID_des_ede3_cbc,	8,	24, },
 	{ CRYPTO_AES_CBC,		NID_aes_128_cbc,	16,	16, },
+	{ CRYPTO_AES_CBC,		NID_aes_192_cbc,	16,	24, },
+	{ CRYPTO_AES_CBC,		NID_aes_256_cbc,	16,	32, },
 	{ CRYPTO_BLF_CBC,		NID_bf_cbc,		8,	16, },
 	{ CRYPTO_CAST_CBC,		NID_cast5_cbc,		8,	16, },
 	{ CRYPTO_SKIPJACK_CBC,		NID_undef,		0,	 0, },
@@ -182,6 +184,10 @@
 		return (-1);
 	if (ioctl(fd, CRIOGET, &retfd) == -1)
 		return (-1);
+	if (retfd == -1)
+		retfd = fd;
+/*	else			fix for PR=138881 */
+/*		close(fd);	fix for PR=138881 */
 
 	/* close on exec */
 	if (fcntl(retfd, F_SETFD, 1) == -1) {
@@ -202,48 +208,16 @@
 	return fd;
 }
 
-/*
- * XXXX this needs to be set for each alg - and determined from
- * a running card.
- */
-static int
-cryptodev_max_iv(int cipher)
-{
-	int i;
-
-	for (i = 0; ciphers[i].id; i++)
-		if (ciphers[i].id == cipher)
-			return (ciphers[i].ivmax);
-	return (0);
-}
-
-/*
- * XXXX this needs to be set for each alg - and determined from
- * a running card. For now, fake it out - but most of these
- * for real devices should return 1 for the supported key
- * sizes the device can handle.
- */
-static int
-cryptodev_key_length_valid(int cipher, int len)
-{
-	int i;
-
-	for (i = 0; ciphers[i].id; i++)
-		if (ciphers[i].id == cipher)
-			return (ciphers[i].keylen == len);
-	return (0);
-}
-
 /* convert libcrypto nids to cryptodev */
-static int
+static struct dev_crypto_cipher *
 cipher_nid_to_cryptodev(int nid)
 {
 	int i;
 
-	for (i = 0; ciphers[i].id; i++)
-		if (ciphers[i].nid == nid)
-			return (ciphers[i].id);
-	return (0);
+	for (i = 0; ciphers[i].c_id; i++)
+		if (ciphers[i].c_nid == nid)
+			return (&ciphers[i]);
+	return (NULL);
 }
 
 /*
@@ -266,15 +240,15 @@
 	memset(&sess, 0, sizeof(sess));
 	sess.key = (caddr_t)"123456781234567812345678";
 
-	for (i = 0; ciphers[i].id && count < CRYPTO_ALGORITHM_MAX; i++) {
-		if (ciphers[i].nid == NID_undef)
+	for (i = 0; ciphers[i].c_id && count < CRYPTO_ALGORITHM_MAX; i++) {
+		if (ciphers[i].c_nid == NID_undef)
 			continue;
-		sess.cipher = ciphers[i].id;
-		sess.keylen = ciphers[i].keylen;
+		sess.cipher = ciphers[i].c_id;
+		sess.keylen = ciphers[i].c_keylen;
 		sess.mac = 0;
 		if (ioctl(fd, CIOCGSESSION, &sess) != -1 &&
 		    ioctl(fd, CIOCFSESSION, &sess.ses) != -1)
-			nids[count++] = ciphers[i].nid;
+			nids[count++] = ciphers[i].c_nid;
 	}
 	close(fd);
 
@@ -427,15 +401,15 @@
 {
 	struct dev_crypto_state *state = ctx->cipher_data;
 	struct session_op *sess = &state->d_sess;
-	int cipher;
+	struct dev_crypto_cipher *cipher;
 
-	if ((cipher = cipher_nid_to_cryptodev(ctx->cipher->nid)) == NID_undef)
+	if ((cipher = cipher_nid_to_cryptodev(ctx->cipher->nid)) == NULL)
 		return (0);
 
-	if (ctx->cipher->iv_len > cryptodev_max_iv(cipher))
+	if (ctx->cipher->iv_len > cipher->c_ivmax)
 		return (0);
 
-	if (!cryptodev_key_length_valid(cipher, ctx->key_len))
+	if (ctx->key_len != cipher->c_keylen)
 		return (0);
 
 	memset(sess, 0, sizeof(struct session_op));
@@ -445,7 +419,7 @@
 
 	sess->key = (unsigned char *)key;
 	sess->keylen = ctx->key_len;
-	sess->cipher = cipher;
+	sess->cipher = cipher->c_id;
 
 	if (ioctl(state->d_fd, CIOCGSESSION, sess) == -1) {
 		close(state->d_fd);
@@ -550,7 +524,7 @@
 	NULL
 };
 
-const EVP_CIPHER cryptodev_aes_cbc = {
+const EVP_CIPHER cryptodev_aes_128_cbc = {
 	NID_aes_128_cbc,
 	16, 16, 16,
 	EVP_CIPH_CBC_MODE,
@@ -563,6 +537,32 @@
 	NULL
 };
 
+const EVP_CIPHER cryptodev_aes_192_cbc = {
+	NID_aes_192_cbc,
+	16, 24, 16,
+	EVP_CIPH_CBC_MODE,
+	cryptodev_init_key,
+	cryptodev_cipher,
+	cryptodev_cleanup,
+	sizeof(struct dev_crypto_state),
+	EVP_CIPHER_set_asn1_iv,
+	EVP_CIPHER_get_asn1_iv,
+	NULL
+};
+
+const EVP_CIPHER cryptodev_aes_256_cbc = {
+	NID_aes_256_cbc,
+	16, 32, 16,
+	EVP_CIPH_CBC_MODE,
+	cryptodev_init_key,
+	cryptodev_cipher,
+	cryptodev_cleanup,
+	sizeof(struct dev_crypto_state),
+	EVP_CIPHER_set_asn1_iv,
+	EVP_CIPHER_get_asn1_iv,
+	NULL
+};
+
 /*
  * Registered by the ENGINE when used to find out how to deal with
  * a particular NID in the ENGINE. this says what we'll do at the
@@ -589,7 +589,13 @@
 		*cipher = &cryptodev_cast_cbc;
 		break;
 	case NID_aes_128_cbc:
-		*cipher = &cryptodev_aes_cbc;
+		*cipher = &cryptodev_aes_128_cbc;
+		break;
+	case NID_aes_192_cbc:
+		*cipher = &cryptodev_aes_192_cbc;
+		break;
+	case NID_aes_256_cbc:
+		*cipher = &cryptodev_aes_256_cbc;
 		break;
 	default:
 		*cipher = NULL;
