--- third_party/boringssl/src/crypto/ex_data.c.orig	2021-03-13 00:03:31 UTC
+++ third_party/boringssl/src/crypto/ex_data.c
@@ -186,7 +186,9 @@ int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad, int index, 
     }
   }
 
-  sk_void_set(ad->sk, index, val);
+  // expression result unused; should this cast be to 'void'?
+  // seems it should, feel free to investigate those #def
+  (void) sk_void_set(ad->sk, index, val);
   return 1;
 }
 
