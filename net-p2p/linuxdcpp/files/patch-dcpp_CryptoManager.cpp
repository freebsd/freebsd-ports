--- dcpp/CryptoManager.cpp.orig	2011-04-17 17:57:09 UTC
+++ dcpp/CryptoManager.cpp
@@ -107,12 +107,20 @@ CryptoManager::CryptoManager()
                 };
 
 		if(dh) {
-			dh->p = BN_bin2bn(dh4096_p, sizeof(dh4096_p), 0);
-			dh->g = BN_bin2bn(dh4096_g, sizeof(dh4096_g), 0);
+			BIGNUM *p, *g;
 
-			if (!dh->p || !dh->g) {
+			p = BN_bin2bn(dh4096_p, sizeof(dh4096_p), 0);
+			g = BN_bin2bn(dh4096_g, sizeof(dh4096_g), 0);
+
+			if (!p || !g) {
 				dh.reset();
 			} else {
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+				dh->p = p;
+				dh->g = g;
+#else
+				DH_set0_pqg(dh, p, NULL, g);
+#endif
 				SSL_CTX_set_options(serverContext, SSL_OP_SINGLE_DH_USE);
 				SSL_CTX_set_options(serverVerContext, SSL_OP_SINGLE_DH_USE);
 				SSL_CTX_set_tmp_dh(serverContext, (DH*)dh);
