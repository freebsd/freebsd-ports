--- qca-tls.cpp.orig	Fri Aug 26 10:47:35 2005
+++ qca-tls.cpp	Fri Aug 26 10:51:07 2005
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
