--- ./src/networks/donkey/donkeyClient.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/donkey/donkeyClient.ml	Mon May 15 13:03:12 2006
@@ -862,7 +862,7 @@
   match file.file_swarmer with
     None -> false
   | Some swarmer ->
-      let bitmap = CommonSwarming.verified_bitmap swarmer in
+      let bitmap = CommonSwarming.chunks_verified_bitmap swarmer in
       let rec iter bitmap chunks i len =
         if i = len then false else
         if Bitv.get chunks i && bitmap.[i] < '2' then true else
@@ -879,7 +879,7 @@
       match file.file_swarmer with
         None -> ()
       | Some swarmer ->
-          lprintf_nl () "   %s" (CommonSwarming.verified_bitmap swarmer);
+          lprintf_nl () "   %s" (CommonSwarming.chunks_verified_bitmap swarmer);
     end;
   
   let chunks = 
@@ -1946,7 +1946,7 @@
                        asume that we have all chunks! *)
                     Bitv.create file.file_nchunks true
               | Some swarmer ->
-                  let bitmap = CommonSwarming.verified_bitmap swarmer in
+                  let bitmap = CommonSwarming.chunks_verified_bitmap swarmer in
                   Bitv.init (String.length bitmap) 
                       (fun i -> bitmap.[i] = '3')
                   (* This is not very smart, as we might get banned for this request.
@@ -2538,7 +2538,7 @@
             match file.file_swarmer with
               None -> None
             | Some swarmer ->
-                let bitmap = CommonSwarming.verified_bitmap swarmer in
+                let bitmap = CommonSwarming.chunks_verified_bitmap swarmer in
                 let chunks = 
                   Bitv.init (String.length bitmap) 
                   (fun i -> bitmap.[i] = '3')
