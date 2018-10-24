--- src/pam_p11.c.orig	2018-05-04 14:52:04 UTC
+++ src/pam_p11.c
@@ -31,6 +31,17 @@
 #include <openssl/crypto.h>
 #include <libp11.h>
 
+/* openssl deprecated API emulation */
+#ifndef HAVE_EVP_MD_CTX_NEW
+#define EVP_MD_CTX_new()	EVP_MD_CTX_create()
+#endif
+#ifndef HAVE_EVP_MD_CTX_FREE
+#define EVP_MD_CTX_free(ctx)	EVP_MD_CTX_destroy((ctx))
+#endif
+#ifndef HAVE_EVP_MD_CTX_RESET
+#define EVP_MD_CTX_reset(ctx)	EVP_MD_CTX_cleanup((ctx))
+#endif
+
 #ifdef ENABLE_NLS
 #include <libintl.h>
 #include <locale.h>
@@ -53,7 +64,7 @@
 #include <security/pam_ext.h>
 #else
 #define pam_syslog(handle, level, msg...) syslog(level, ## msg)
-static int pam_vprompt(pam_handle_t *pamh, int style, char **response,
+int pam_vprompt(const pam_handle_t *pamh, int style, char **response,
 		const char *fmt, va_list args)
 {
 	int r = PAM_CRED_INSUFFICIENT;
@@ -549,7 +560,7 @@ static int key_find(pam_handle_t *pamh, 
 	return 0;
 }
 
-static int randomize(pam_handle_t *pamh, unsigned char *r, unsigned int r_len)
+static int randomize(pam_handle_t *pamh, unsigned char *r, int r_len)
 {
 	int ok = 0;
 	int fd = open("/dev/urandom", O_RDONLY);
@@ -572,7 +583,7 @@ static int key_verify(pam_handle_t *pamh
 	unsigned char signature[256];
 	unsigned int siglen = sizeof signature;
 	const EVP_MD *md = EVP_sha1();
-	EVP_MD_CTX *md_ctx = EVP_MD_CTX_create();
+	EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
 	EVP_PKEY *privkey = PKCS11_get_private_key(authkey);
 	EVP_PKEY *pubkey = PKCS11_get_public_key(authkey);
 
@@ -590,7 +601,7 @@ static int key_verify(pam_handle_t *pamh
 			|| !EVP_SignInit(md_ctx, md)
 			|| !EVP_SignUpdate(md_ctx, challenge, sizeof challenge)
 			|| !EVP_SignFinal(md_ctx, signature, &siglen, privkey)
-			|| !EVP_MD_CTX_cleanup(md_ctx)
+			|| !EVP_MD_CTX_reset(md_ctx)
 			|| !EVP_VerifyInit(md_ctx, md)
 			|| !EVP_VerifyUpdate(md_ctx, challenge, sizeof challenge)
 			|| 1 != EVP_VerifyFinal(md_ctx, signature, siglen, pubkey)) {
@@ -607,7 +618,7 @@ err:
 	if (NULL != privkey)
 		EVP_PKEY_free(privkey);
 	if (NULL != md_ctx) {
-		EVP_MD_CTX_destroy(md_ctx);
+		EVP_MD_CTX_free(md_ctx);
 	}
 	return ok;
 }
