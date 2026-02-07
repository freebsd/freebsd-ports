--- uutil.ml.orig	2024-02-06 20:32:31 UTC
+++ uutil.ml
@@ -34,7 +34,7 @@ let hash2 x y = (17 * x + 257 * y) land 0x3FFFFFFF
 
 let hash2 x y = (17 * x + 257 * y) land 0x3FFFFFFF
 
-external hash_param : int -> int -> 'a -> int = "caml_hash_univ_param" "noalloc"
+external hash_param : int -> int -> 'a -> int = "unsn_hash_univ_param" "noalloc"
 
 let hash x = hash_param 10 100 x
 
