--- sslscan.c.orig	2016-11-06 13:27:11 UTC
+++ sslscan.c
@@ -829,7 +829,7 @@ int testCompression(struct sslCheckOptio
 #endif
                         {
                             printf("%sOpenSSL version does not support compression%s\n", COL_RED, RESET);
-                            printf("%sRebuild with zlib1g-dev package for zlib support%s\n\n", COL_RED, RESET);
+                            printf("\n");
                         }
 
                         // Disconnect SSL over socket
@@ -1155,14 +1155,14 @@ int testRenegotiation(struct sslCheckOpt
                                 printf_verbose("Attempting SSL_do_handshake(ssl)\n");
                                 SSL_do_handshake(ssl); // Send renegotiation request to server //TODO :: XXX hanging here
 
-                                if (ssl->state == SSL_ST_OK)
+                                if (SSL_get_state(ssl) == SSL_ST_OK)
                                 {
                                     res = SSL_do_handshake(ssl); // Send renegotiation request to server
                                     if( res != 1 )
                                     {
                                         printf_error("\n\nSSL_do_handshake() call failed\n");
                                     }
-                                    if (ssl->state == SSL_ST_OK)
+                                    if (SSL_get_state(ssl) == SSL_ST_OK)
                                     {
                                         /* our renegotiation is complete */
                                         renOut->supported = true;
@@ -1504,7 +1504,11 @@ int testCipher(struct sslCheckOptions *o
                     return false;
                 }
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 		cipherid = SSL_CIPHER_get_id(sslCipherPointer);
+#else
+		cipherid = sslCipherPointer->id;
+#endif
 		cipherid = cipherid & 0x00ffffff;  // remove first byte which is the version (0x03 for TLSv1/SSLv3)
 
                 // Show Cipher Status
