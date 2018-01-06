--- src/3rdparty/chromium/third_party/boringssl/src/crypto/ex_data.c.orig	2017-01-26 00:50:08 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/ex_data.c
@@ -188,7 +188,9 @@ int CRYPTO_set_ex_data(CRYPTO_EX_DATA *a
     }
   }
 
-  sk_void_set(ad->sk, index, val);
+  // expression result unused; should this cast be to 'void'?
+  // seems it should, feel free to investigate those #def
+  (void) sk_void_set(ad->sk, index, val);
   return 1;
 }
 
