--- src/networks/donkey/donkeyClient.ml.orig	2020-07-06 02:50:39 UTC
+++ src/networks/donkey/donkeyClient.ml
@@ -811,8 +811,6 @@ another better way, since this functionnality is still
         end
 
 
-external hash_param : int -> int -> 'a -> int = "caml_hash_univ_param" "noalloc"
-let hash x = hash_param 10 100 x
 
 let shared_of_file file =
   match file.file_shared with
