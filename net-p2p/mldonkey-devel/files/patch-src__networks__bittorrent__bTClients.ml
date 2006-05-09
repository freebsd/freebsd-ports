--- ./src/networks/bittorrent/bTClients.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/bittorrent/bTClients.ml	Sun May  7 06:39:10 2006
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
 
 
