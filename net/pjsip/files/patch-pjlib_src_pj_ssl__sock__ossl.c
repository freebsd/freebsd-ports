--- pjlib/src/pj/ssl_sock_ossl.c.orig	2017-09-14 05:03:45 UTC
+++ pjlib/src/pj/ssl_sock_ossl.c
@@ -53,7 +53,7 @@
 #include <openssl/rand.h>
 #include <openssl/opensslconf.h>
 
-#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
 
 #   include <openssl/obj_mac.h>
 
@@ -111,7 +111,7 @@ static unsigned get_nid_from_cid(unsigned cid)
 #endif
 
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 #  define OPENSSL_NO_SSL2	    /* seems to be removed in 1.1.0 */
 #  define M_ASN1_STRING_data(x)	    ASN1_STRING_get0_data(x)
 #  define M_ASN1_STRING_length(x)   ASN1_STRING_length(x)
@@ -126,7 +126,7 @@ static unsigned get_nid_from_cid(unsigned cid)
 
 
 #ifdef _MSC_VER
-#  if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#  if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 #    pragma comment(lib, "libcrypto")
 #    pragma comment(lib, "libssl")
 #    pragma comment(lib, "crypt32")
@@ -535,13 +535,13 @@ static pj_status_t init_openssl(void)
     pj_assert(status == PJ_SUCCESS);
 
     /* Init OpenSSL lib */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     SSL_library_init();
     SSL_load_error_strings();
 #else
     OPENSSL_init_ssl(0, NULL);
 #endif
-#if OPENSSL_VERSION_NUMBER < 0x009080ffL
+#if OPENSSL_VERSION_NUMBER < 0x009080ffL || defined(LIBRESSL_VERSION_NUMBER)
     /* This is now synonym of SSL_library_init() */
     OpenSSL_add_all_algorithms();
 #endif
@@ -556,7 +556,7 @@ static pj_status_t init_openssl(void)
 	int nid;
 	const char *cname;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 	meth = (SSL_METHOD*)SSLv23_server_method();
 	if (!meth)
 	    meth = (SSL_METHOD*)TLSv1_server_method();
@@ -599,7 +599,7 @@ static pj_status_t init_openssl(void)
 
 	SSL_set_session(ssl, SSL_SESSION_new());
 
-#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
 	openssl_curves_num = SSL_get_shared_curve(ssl,-1);
 	if (openssl_curves_num > PJ_ARRAY_SIZE(openssl_curves))
 	    openssl_curves_num = PJ_ARRAY_SIZE(openssl_curves);
@@ -768,7 +768,7 @@ static pj_status_t create_ssl(pj_ssl_sock_t *ssock)
     BIO *bio;
     DH *dh;
     long options;
-#if !defined(OPENSSL_NO_ECDH) && OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if !defined(OPENSSL_NO_ECDH) && OPENSSL_VERSION_NUMBER >= 0x10000000L && !defined(LIBRESSL_VERSION_NUMBER)
     EC_KEY *ecdh;
 #endif
     SSL_METHOD *ssl_method = NULL;
@@ -791,7 +791,7 @@ static pj_status_t create_ssl(pj_ssl_sock_t *ssock)
 	ssock->param.proto = PJ_SSL_SOCK_PROTO_SSL23;
 
     /* Determine SSL method to use */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     switch (ssock->param.proto) {
     case PJ_SSL_SOCK_PROTO_TLS1:
 	ssl_method = (SSL_METHOD*)TLSv1_method();
@@ -927,7 +927,7 @@ static pj_status_t create_ssl(pj_ssl_sock_t *ssock)
 		    if (dh != NULL) {
 			if (SSL_CTX_set_tmp_dh(ctx, dh)) {
 			    options = SSL_OP_CIPHER_SERVER_PREFERENCE |
-    #if !defined(OPENSSL_NO_ECDH) && OPENSSL_VERSION_NUMBER >= 0x10000000L
+    #if !defined(OPENSSL_NO_ECDH) && OPENSSL_VERSION_NUMBER >= 0x10000000L && !defined(LIBRESSL_VERSION_NUMBER)
 				      SSL_OP_SINGLE_ECDH_USE |
     #endif
 				      SSL_OP_SINGLE_DH_USE;
@@ -995,7 +995,7 @@ static pj_status_t create_ssl(pj_ssl_sock_t *ssock)
 	if (SSL_CTX_ctrl(ctx, SSL_CTRL_SET_ECDH_AUTO, 1, NULL)) {
 	    PJ_LOG(4,(ssock->pool->obj_name, "SSL ECDH initialized "
 		      "(automatic), faster PFS ciphers enabled"));
-    #if !defined(OPENSSL_NO_ECDH) && OPENSSL_VERSION_NUMBER >= 0x10000000L
+    #if !defined(OPENSSL_NO_ECDH) && OPENSSL_VERSION_NUMBER >= 0x10000000L && !defined(LIBRESSL_VERSION_NUMBER)
 	} else {
 	    /* enables AES-128 ciphers, to get AES-256 use NID_secp384r1 */
 	    ecdh = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
@@ -1228,7 +1228,7 @@ static pj_status_t set_cipher_list(pj_ssl_sock_t *ssoc
 
 static pj_status_t set_curves_list(pj_ssl_sock_t *ssock)
 {
-#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if !defined(OPENSSL_NO_EC) && OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
     int ret;
     int curves[PJ_SSL_SOCK_MAX_CURVES];
     unsigned cnt;
@@ -1259,7 +1259,7 @@ static pj_status_t set_curves_list(pj_ssl_sock_t *ssoc
 
 static pj_status_t set_sigalgs(pj_ssl_sock_t *ssock)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
     int ret;
 
     if (ssock->param.sigalgs.ptr && ssock->param.sigalgs.slen) {
