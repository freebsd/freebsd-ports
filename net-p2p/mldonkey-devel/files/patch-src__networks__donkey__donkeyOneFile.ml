--- ./src/networks/donkey/donkeyOneFile.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/donkey/donkeyOneFile.ml	Mon May 15 13:03:12 2006
@@ -166,7 +166,7 @@
       match file.file_swarmer with
         None -> ()
       | Some swarmer ->
-          let bitmap = CommonSwarming.verified_bitmap swarmer in
+          let bitmap = CommonSwarming.chunks_verified_bitmap swarmer in
 (*          lprintf "Verified bitmap: [%s]\n" bitmap; *)
           let rec iter i =
             if i =  String.length bitmap then true
@@ -197,7 +197,7 @@
           match file.file_swarmer with
             None -> ()
           | Some swarmer ->
-              let bitmap = CommonSwarming.verified_bitmap swarmer in
+              let bitmap = CommonSwarming.chunks_verified_bitmap swarmer in
               let rec iter i len =
                 if i < len then
                   if bitmap.[i] = '3' then
@@ -217,7 +217,7 @@
           (f, chunks, up) :: tail ->
             if f != file then iter tail
             else begin
-                CommonSwarming.update_uploader up
+                CommonSwarming.update_uploader_intervals up
                 (AvailableBitv client_chunks);
                 Bitv.blit client_chunks 0 chunks 0 (Bitv.length chunks)
               end
@@ -239,8 +239,7 @@
   match c.client_download with
     None -> ()
   | Some (file, up) ->
-      CommonSwarming.clear_uploader_block up;
-      CommonSwarming.clear_uploader_ranges up;
+      CommonSwarming.unregister_uploader up;
       c.client_download <- None
 
 let send_get_range_request c file ranges = 
@@ -333,7 +332,7 @@
           let rec iter n =
             if n < 3 then
               try
-                ignore (CommonSwarming.find_range up);
+                ignore (CommonSwarming.find_range up zone_size);
                 iter (n+1)
               with 
                 Not_found -> n
