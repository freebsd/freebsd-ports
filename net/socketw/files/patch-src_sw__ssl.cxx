--- src/sw_ssl.cxx.orig	2018-09-18 09:32:11 UTC
+++ src/sw_ssl.cxx
@@ -4,7 +4,7 @@
 // Started 020316
 //
 // License: LGPL v2.1+ (see the file LICENSE)
-// (c)2002-2003 Anders Lindström
+// (c)2002-2003 Anders LindstrÃ¶m
 
 /***********************************************************************
  *  This library is free software; you can redistribute it and/or      *
@@ -22,6 +22,7 @@
 #include <openssl/x509.h>
 #include <openssl/rsa.h>
 #include <openssl/evp.h>
+#include <cstring>
 
 using namespace std;
 
@@ -31,7 +32,25 @@ extern int close(int fd);
 extern int fcntl(int fd, int cmd, long arg);
 #endif
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 
+int X509_get_signature_nid(const X509* peer)
+{
+    return OBJ_obj2nid(peer->sig_alg->algorithm);
+}
+int X509_certificate_type(const X509 *, const EVP_PKEY *pubkey)
+{
+    return pubkey->type;
+}
+
+int SSL_CTX_up_ref(SSL_CTX *ctx)
+{
+    return ctx->references++;
+}
+
+#endif
+
+
 //====================================================================
 //== Helper functions
 //====================================================================
@@ -557,7 +576,8 @@ bool SWSSLSocket::get_peerCert_info(SWSSLSocket::peerC
 		info->version = X509_get_version(peer);
 		
 		// Signature algorithm
-		int nid = OBJ_obj2nid(peer->sig_alg->algorithm);
+
+		int nid = X509_get_signature_nid(peer);
 		if( nid != NID_undef )
 			info->sgnAlgorithm = OBJ_nid2sn(nid);
 		else
@@ -566,7 +586,7 @@ bool SWSSLSocket::get_peerCert_info(SWSSLSocket::peerC
 		// Key algorithm
 		EVP_PKEY *pkey = X509_get_pubkey(peer);
 		if( pkey ){
-			info->keyAlgorithm = OBJ_nid2sn(pkey->type);
+			info->keyAlgorithm = OBJ_nid2sn(X509_certificate_type(peer, pkey));
 			info->keySize = 8 * EVP_PKEY_size(pkey);
 		}else{
 			info->keyAlgorithm = "";
@@ -689,7 +709,8 @@ bool SWSSLSocket::check_cert(SWBaseError *error)
 			}
 		}
 		
-		if( !(cert = BuildCertificate("SocketW session cert", NULL, NULL, evp_pkey)) ){
+                char certificateName[22] = "SocketW session cert\0";
+		if( !(cert = BuildCertificate(certificateName, NULL, NULL, evp_pkey)) ){
 			handle_ERRerror(error, fatal, "SWSSLSocket::handle_crypto_data() ");
 			return false;
 		}
@@ -718,7 +739,7 @@ SWBaseSocket* SWSSLSocket::create(int socketdescriptor
 	// Copy CTX object pointer
 	remoteClass->ctx  = ctx;
 	if( ctx )
-		ctx->references++;  // We don't want our destructor to delete ctx if still in use
+            SSL_CTX_up_ref(ctx);
 	
 	remoteClass->have_cert = have_cert; // Do CTX have cert loaded?
 	
