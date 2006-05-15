--- ./src/networks/bittorrent/bTClients.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/bittorrent/bTClients.ml	Mon May 15 13:03:12 2006
@@ -401,7 +401,7 @@
 (* This must be a seeded file... *)
         String.make (Array.length c.client_file.file_chunks) '3'
     | Some swarmer ->
-        CommonSwarming.verified_bitmap swarmer
+        CommonSwarming.chunks_verified_bitmap swarmer
   in
 
   if !verbose_download then lprintf_nl () "Sending verified bitmap: [%s]" bitmap;
@@ -561,7 +561,7 @@
     match c.client_uploader with
       None ->
         let up = CommonSwarming.register_uploader swarmer (as_client c)
-          (AvailableRanges []) in
+          (AvailableIntervals []) in
         c.client_uploader <- Some up;
         up
     | Some up ->
@@ -581,7 +581,7 @@
     let chunks = c.client_new_chunks in
     c.client_new_chunks <- [];
     List.iter (fun n -> Bitv.set bitmap n true) chunks;
-    CommonSwarming.update_uploader up (AvailableBitv bitmap);
+    CommonSwarming.update_uploader_intervals up (AvailableBitv bitmap);
   end
 
 
@@ -691,7 +691,7 @@
                         c.client_range_waiting <- None;
                         (x,y,r)
                   | None -> 
-                        CommonSwarming.find_range up 
+                        CommonSwarming.find_range up (min max_range_len file.file_piece_size)
                 in
 
                 let (x,y,r) =
@@ -706,7 +706,7 @@
                   c.client_ranges_sent <- c.client_ranges_sent @ [x,y, r];
 (*                CommonSwarming.alloc_range r; *)
                 
-                  let num = CommonSwarming.block_num swarmer b in
+                  let num = CommonSwarming.block_chunk_num swarmer b in
 
                   if !verbose_swarming then 
                     lprintf_nl () "Asking %d For Range %Ld-%Ld" num x y;
@@ -917,7 +917,7 @@
                 disconnect_client c (Closed_for_error "Wrong bitfield length")
               end else begin
 
-                let verified = CommonSwarming.verified_bitmap swarmer in
+                let verified = CommonSwarming.chunks_verified_bitmap swarmer in
 
                 for i = 0 to npieces - 1 do
                   if is_bit_set p i then begin
@@ -952,7 +952,7 @@
             None -> ()
           | Some swarmer ->
               let n = Int64.to_int n in
-              let verified = CommonSwarming.verified_bitmap swarmer in
+              let verified = CommonSwarming.chunks_verified_bitmap swarmer in
               (* lprintf_nl "verified: %c;" verified.[n]; *)
               (* if the peer has a chunk we don't, tell him we're interested and update his bitmap *)
               if verified.[n] < '2' then begin
