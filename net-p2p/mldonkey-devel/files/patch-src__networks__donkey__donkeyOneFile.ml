--- ./src/networks/donkey/donkeyOneFile.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/donkey/donkeyOneFile.ml	Sun May  7 06:39:10 2006
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
