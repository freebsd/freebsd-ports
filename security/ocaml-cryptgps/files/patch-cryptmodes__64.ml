--- cryptmodes_64.ml.orig	2001-03-10 16:43:21 UTC
+++ cryptmodes_64.ml
@@ -52,7 +52,7 @@ module Make_modes (M : Cryptsystem_64.T) =
       if l mod 8 <> 0 then failwith "encrypt_cbc";
 
       let n = l / 8 in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let v = ref iv in
       for i = 0 to n-1 do
@@ -79,7 +79,7 @@ module Make_modes (M : Cryptsystem_64.T) =
 	data'.[j+7] <- Char.chr(v0' land 0xff);
       done;
 
-      !v, data'
+      !v, Bytes.to_string data'
 
 
     let decrypt_cbc k iv data =
@@ -87,7 +87,7 @@ module Make_modes (M : Cryptsystem_64.T) =
       if l mod 8 <> 0 then failwith "decrypt_cbc";
 
       let n = l / 8 in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let v = ref iv in
       for i = 0 to n-1 do
@@ -119,12 +119,12 @@ module Make_modes (M : Cryptsystem_64.T) =
 	v := (x3,x2,x1,x0);
       done;
 
-      !v, data'
+      !v, Bytes.to_string data'
 
 
     let encrypt_cfb8 k iv data =
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr = ref iv in (* shift register *)
       
@@ -139,12 +139,12 @@ module Make_modes (M : Cryptsystem_64.T) =
 	       ((sr0 lsl 8) land 0xff00) lor c);
       done;
 
-      !sr, data'
+      !sr, Bytes.to_string data'
 
 
     let decrypt_cfb8 k iv data = 
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr = ref iv in (* shift register *)
       
@@ -160,7 +160,7 @@ module Make_modes (M : Cryptsystem_64.T) =
 	       ((sr0 lsl 8) land 0xff00) lor c);
       done;
 
-      !sr, data'
+      !sr, Bytes.to_string data'
 
 
     let array_of_quadrupel (n3,n2,n1,n0) =
@@ -182,7 +182,7 @@ module Make_modes (M : Cryptsystem_64.T) =
     let encrypt_cfb64 k iv j data =
       if j < 0 or j > 7 then failwith "encrypt_cfb64";
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr_a = ref (array_of_quadrupel iv) in
       let jc = ref j in
@@ -200,13 +200,13 @@ module Make_modes (M : Cryptsystem_64.T) =
       done;
 
       let sr = quadrupel_of_array !sr_a in
-      sr, !jc, data'
+      sr, !jc, Bytes.to_string data'
 
 
     let decrypt_cfb64 k iv j data =
       if j < 0 or j > 7 then failwith "decrypt_cfb64";
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr_a = ref (array_of_quadrupel iv) in
       let jc = ref j in
@@ -224,13 +224,13 @@ module Make_modes (M : Cryptsystem_64.T) =
       done;
 
       let sr = quadrupel_of_array !sr_a in
-      sr, !jc, data'
+      sr, !jc, Bytes.to_string data'
 
 
     let crypt_ofb k iv j data =
       if j < 0 or j > 7 then failwith "crypt_ofb";
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr_a = ref (array_of_quadrupel iv) in
       let jc = ref j in
@@ -247,7 +247,7 @@ module Make_modes (M : Cryptsystem_64.T) =
       done;
 
       let sr = quadrupel_of_array !sr_a in
-      sr, !jc, data'
+      sr, !jc, Bytes.to_string data'
 
   end
 ;;
@@ -263,7 +263,7 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
       if l mod 8 <> 0 then failwith "encrypt_cbc";
 
       let n = l / 8 in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let vl = ref Int32.zero in
       let vr = ref Int32.zero in
@@ -308,7 +308,7 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
 	data'.[j+7] <- Char.chr(v0' land 0xff);
       done;
 
-      quadruple_of_int32 !vl !vr, data'
+      quadruple_of_int32 !vl !vr, Bytes.to_string data'
 
 
     let decrypt_cbc k iv data =
@@ -316,7 +316,7 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
       if l mod 8 <> 0 then failwith "decrypt_cbc";
 
       let n = l / 8 in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let vl = ref Int32.zero in
       let vr = ref Int32.zero in
@@ -367,12 +367,12 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
 	vr := xr;
       done;
 
-      quadruple_of_int32 !vl !vr, data'
+      quadruple_of_int32 !vl !vr, Bytes.to_string data'
 
 
     let encrypt_cfb8 k iv data =
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr_l = ref Int32.zero in   (* shift register MSB *)
       let sr_r = ref Int32.zero in   (* shift register LSB *)
@@ -396,12 +396,12 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
 	          (Int32.of_int c)
       done;
 
-      quadruple_of_int32 !sr_l !sr_r, data'
+      quadruple_of_int32 !sr_l !sr_r, Bytes.to_string data'
 
 
     let decrypt_cfb8 k iv data = 
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr_l = ref Int32.zero in   (* shift register MSB *)
       let sr_r = ref Int32.zero in   (* shift register LSB *)
@@ -426,7 +426,7 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
 	          (Int32.of_int c)
       done;
 
-      quadruple_of_int32 !sr_l !sr_r, data'
+      quadruple_of_int32 !sr_l !sr_r, Bytes.to_string data'
 
 
     let mask =
@@ -439,7 +439,7 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
     let encrypt_cfb64 k iv j data =
       if j < 0 or j > 7 then failwith "encrypt_cfb64";
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr_l = ref Int32.zero in   (* shift register MSB *)
       let sr_r = ref Int32.zero in   (* shift register LSB *)
@@ -479,13 +479,13 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
 	jc := (!jc + 1) mod 8;
       done;
 
-      quadruple_of_int32 !sr_l !sr_r, !jc, data'
+      quadruple_of_int32 !sr_l !sr_r, !jc, Bytes.to_string data'
 
 
     let decrypt_cfb64 k iv j data =
       if j < 0 or j > 7 then failwith "decrypt_cfb64";
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr_l = ref Int32.zero in   (* shift register MSB *)
       let sr_r = ref Int32.zero in   (* shift register LSB *)
@@ -525,13 +525,13 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
 	jc := (!jc + 1) mod 8;
       done;
 
-      quadruple_of_int32 !sr_l !sr_r, !jc, data'
+      quadruple_of_int32 !sr_l !sr_r, !jc, Bytes.to_string data'
 
 
     let crypt_ofb k iv j data =
       if j < 0 or j > 7 then failwith "crypt_ofb";
       let l = String.length data in
-      let data' = String.create l in
+      let data' = Bytes.create l in
 
       let sr_l = ref Int32.zero in   (* shift register MSB *)
       let sr_r = ref Int32.zero in   (* shift register LSB *)
@@ -561,7 +561,7 @@ module Make_modes_int32 (M : Cryptsystem_64.T) =
 	jc := (!jc + 1) mod 8;
       done;
 
-      quadruple_of_int32 !sr_l !sr_r, !jc, data'
+      quadruple_of_int32 !sr_l !sr_r, !jc, Bytes.to_string data'
 
   end
 ;;
