--- sslscan.c.orig	2016-03-24 21:02:55 UTC
+++ sslscan.c
@@ -788,7 +788,7 @@ int testCompression(struct sslCheckOptio
 #endif
                         {
                             printf("%sOpenSSL version does not support compression%s\n", COL_RED, RESET);
-                            printf("%sRebuild with zlib1g-dev package for zlib support%s\n\n", COL_RED, RESET);
+                            printf("\n");
                         }
 
                         // Disconnect SSL over socket
@@ -1291,7 +1291,11 @@ int testCipher(struct sslCheckOptions *o
                     return false;
                 }
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 		cipherid = SSL_CIPHER_get_id(sslCipherPointer);
+#else
+		cipherid = sslCipherPointer->id;
+#endif
 		cipherid = cipherid & 0x00ffffff;  // remove first byte which is the version (0x03 for TLSv1/SSLv3)
 
                 // Show Cipher Status
