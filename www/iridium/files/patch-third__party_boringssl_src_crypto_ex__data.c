--- third_party/boringssl/src/crypto/ex_data.c.orig	2017-04-19 19:07:42 UTC
+++ third_party/boringssl/src/crypto/ex_data.c
@@ -188,7 +188,9 @@ int CRYPTO_set_ex_data(CRYPTO_EX_DATA *a
     }
   }
 
-  sk_void_set(ad->sk, index, val);
+  // expression result unused; should this cast be to 'void'?
+  // seems it should, feel free to investigate those #def
+  (void) sk_void_set(ad->sk, index, val);
   return 1;
 }
 
