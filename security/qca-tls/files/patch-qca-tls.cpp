--- qca-tls.cpp.orig	2003-12-10 19:53:57.000000000 +0300
+++ qca-tls.cpp	2012-02-28 14:06:08.000000000 +0400
@@ -454,7 +454,11 @@
 			if(!r) {
 				// try this other public function, for whatever reason
 				p = (void *)in;
+#ifdef OSSL_098
+				r = d2i_RSA_PUBKEY(NULL, (const unsigned char **)&p, len);
+#else
 				r = d2i_RSA_PUBKEY(NULL, (unsigned char **)&p, len);
+#endif
 			}
 			if(r) {
 				if(pub) {
@@ -799,7 +803,11 @@
 	bool createFromDER(const char *in, unsigned int len)
 	{
 		unsigned char *p = (unsigned char *)in;
+#ifdef OSSL_098
+		X509 *t = d2i_X509(NULL, (const unsigned char**)&p, len);
+#else
 		X509 *t = d2i_X509(NULL, &p, len);
+#endif
 		if(!t)
 			return false;
 		fromX509(t);
@@ -945,7 +953,11 @@
 	RSAKeyContext *key;
 
 	SSL *ssl;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+	const SSL_METHOD *method;
+#else
 	SSL_METHOD *method;
+#endif
 	SSL_CTX *context;
 	BIO *rbio, *wbio;
 	CertContext cc;
