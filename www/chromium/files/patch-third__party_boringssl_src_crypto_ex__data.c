--- third_party/boringssl/src/crypto/ex_data.c.orig	2016-08-03 22:03:20.000000000 +0300
+++ third_party/boringssl/src/crypto/ex_data.c	2016-09-17 04:02:25.959140000 +0300
@@ -188,7 +188,9 @@
     }
   }
 
-  sk_void_set(ad->sk, index, val);
+  // expression result unused; should this cast be to 'void'?
+  // seems it should, feel free to investigate those #def
+  (void) sk_void_set(ad->sk, index, val);
   return 1;
 }
 
