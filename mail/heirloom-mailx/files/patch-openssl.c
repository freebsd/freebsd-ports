--- openssl.c.orig	2007-08-04 11:38:03 UTC
+++ openssl.c
@@ -101,12 +101,17 @@ static void sslcatch(int s);
 static int ssl_rand_init(void);
 static void ssl_init(void);
 static int ssl_verify_cb(int success, X509_STORE_CTX *store);
-static SSL_METHOD *ssl_select_method(const char *uhp);
+static const SSL_METHOD *ssl_select_method(const char *uhp);
 static void ssl_load_verifications(struct sock *sp);
 static void ssl_certificate(struct sock *sp, const char *uhp);
 static enum okay ssl_check_host(const char *server, struct sock *sp);
+#ifdef HAVE_STACK_OF
+static int smime_verify(struct message *m, int n, STACK_OF(X509) *chain,
+		X509_STORE *store);
+#else
 static int smime_verify(struct message *m, int n, STACK *chain,
 		X509_STORE *store);
+#endif
 static EVP_CIPHER *smime_cipher(const char *name);
 static int ssl_password_cb(char *buf, int size, int rwflag, void *userdata);
 static FILE *smime_sign_cert(const char *xname, const char *xname2, int warn);
@@ -130,6 +135,7 @@ ssl_rand_init(void)
 	char *cp;
 	int state = 0;
 
+#ifndef OPENSSL_NO_EGD
 	if ((cp = value("ssl-rand-egd")) != NULL) {
 		cp = expand(cp);
 		if (RAND_egd(cp) == -1) {
@@ -138,7 +144,9 @@ ssl_rand_init(void)
 					cp);
 		} else
 			state = 1;
-	} else if ((cp = value("ssl-rand-file")) != NULL) {
+	} else 
+#endif /* OPENSSL_NO_EGD */
+	if ((cp = value("ssl-rand-file")) != NULL) {
 		cp = expand(cp);
 		if (RAND_load_file(cp, 1024) == -1) {
 			fprintf(stderr, catgets(catd, CATSET, 246,
@@ -203,19 +211,25 @@ ssl_verify_cb(int success, X509_STORE_CT
 	return 1;
 }
 
-static SSL_METHOD *
+static const SSL_METHOD *
 ssl_select_method(const char *uhp)
 {
-	SSL_METHOD *method;
+	const SSL_METHOD *method;
 	char	*cp;
 
 	cp = ssl_method_string(uhp);
 	if (cp != NULL) {
+#ifndef OPENSSL_NO_SSL2
 		if (equal(cp, "ssl2"))
 			method = SSLv2_client_method();
-		else if (equal(cp, "ssl3"))
+		else
+#endif
+#ifndef OPENSSL_NO_SSL3_METHOD
+		if (equal(cp, "ssl3"))
 			method = SSLv3_client_method();
-		else if (equal(cp, "tls1"))
+		else
+#endif
+		if (equal(cp, "tls1"))
 			method = TLSv1_client_method();
 		else {
 			fprintf(stderr, catgets(catd, CATSET, 244,
@@ -308,7 +322,11 @@ ssl_check_host(const char *server, struc
 	X509 *cert;
 	X509_NAME *subj;
 	char data[256];
+#ifdef HAVE_STACK_OF
+	STACK_OF(GENERAL_NAME)	*gens;
+#else
 	/*GENERAL_NAMES*/STACK	*gens;
+#endif
 	GENERAL_NAME	*gen;
 	int	i;
 
@@ -357,7 +375,8 @@ ssl_open(const char *server, struct sock
 
 	ssl_init();
 	ssl_set_vrfy_level(uhp);
-	if ((sp->s_ctx = SSL_CTX_new(ssl_select_method(uhp))) == NULL) {
+	if ((sp->s_ctx =
+	     SSL_CTX_new((SSL_METHOD *)ssl_select_method(uhp))) == NULL) {
 		ssl_gen_err(catgets(catd, CATSET, 261, "SSL_CTX_new() failed"));
 		return STOP;
 	}
@@ -496,7 +515,11 @@ smime_sign(FILE *ip, struct header *head
 }
 
 static int
+#ifdef HAVE_STACK_OF
+smime_verify(struct message *m, int n, STACK_OF(X509) *chain, X509_STORE *store)
+#else
 smime_verify(struct message *m, int n, STACK *chain, X509_STORE *store)
+#endif
 {
 	struct message	*x;
 	char	*cp, *sender, *to, *cc, *cnttype;
@@ -505,7 +528,12 @@ smime_verify(struct message *m, int n, S
 	off_t	size;
 	BIO	*fb, *pb;
 	PKCS7	*pkcs7;
+#ifdef HAVE_STACK_OF
+	STACK_OF(X509)	*certs;
+	STACK_OF(GENERAL_NAME)	*gens;
+#else
 	STACK	*certs, *gens;
+#endif
 	X509	*cert;
 	X509_NAME	*subj;
 	char	data[LINESIZE];
@@ -614,7 +642,11 @@ cverify(void *vp)
 {
 	int	*msgvec = vp, *ip;
 	int	ec = 0;
+#ifdef HAVE_STACK_OF
+	STACK_OF(X509)	*chain = NULL;
+#else
 	STACK	*chain = NULL;
+#endif
 	X509_STORE	*store;
 	char	*ca_dir, *ca_file;
 
@@ -687,7 +719,11 @@ smime_encrypt(FILE *ip, const char *cert
 	X509	*cert;
 	PKCS7	*pkcs7;
 	BIO	*bb, *yb;
+#ifdef HAVE_STACK_OF
+	STACK_OF(X509)	*certs;
+#else
 	STACK	*certs;
+#endif
 	EVP_CIPHER	*cipher;
 
 	certfile = expand((char *)certfile);
@@ -950,9 +986,14 @@ smime_certsave(struct message *m, int n,
 	off_t	size;
 	BIO	*fb, *pb;
 	PKCS7	*pkcs7;
+#ifdef HAVE_STACK_OF
+	STACK_OF(X509)	*certs;
+	STACK_OF(X509)	*chain = NULL;
+#else
 	STACK	*certs;
-	X509	*cert;
 	STACK	*chain = NULL;
+#endif
+	X509	*cert;
 	enum okay	ok = OKAY;
 
 	message_number = n;
