--- lib/gnutls_cipher.c.orig	2013-02-04 12:53:03.000000000 +0400
+++ lib/gnutls_cipher.c	2013-02-04 12:53:03.000000000 +0400
@@ -561,6 +561,8 @@
           return GNUTLS_E_DECRYPTION_FAILED;
         }
       pad = ciphertext.data[ciphertext.size - 1];   /* pad */
+      if (pad+1 > ciphertext.size-hash_size)
+        pad_failed = GNUTLS_E_DECRYPTION_FAILED;
 
       /* Check the pading bytes (TLS 1.x). 
        * Note that we access all 256 bytes of ciphertext for padding check
