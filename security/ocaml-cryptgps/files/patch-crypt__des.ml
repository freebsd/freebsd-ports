--- crypt_des.ml.orig	2001-03-10 16:43:21 UTC
+++ crypt_des.ml
@@ -54,12 +54,12 @@ let set_parity key =
   let l_key = String.length key in
   if l_key <> 8 then 
     failwith "Crypt_des: invalid key length";
-  let key' = String.copy key in
+  let key' = Bytes.of_string key in
   for i = 0 to 7 do
     let k = Char.code key.[i] in
     key'.[i] <- Char.chr(odd_parity.(k))
   done;
-  key'
+  Bytes.to_string key'
 ;;
   
 
