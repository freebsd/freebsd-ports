--- src/networks/donkey/donkeyOneFile.ml	18 Aug 2005 13:00:03 -0000	1.26
+++ src/networks/donkey/donkeyOneFile.ml	29 Aug 2005 00:04:10 -0000
@@ -429,7 +429,6 @@
           
           set_client_state c (Connected_downloading (file_num file));
           let len64 = Int64.of_int bloc_len in
-          count_download c file len64;
           network_must_update network;
 
 (* TODO: verify the received data has been requested *)
@@ -462,8 +461,7 @@
 (*            List.iter Int64Swarmer.alloc_range c.client_ranges; *)
           let new_downloaded = 
             Int64Swarmer.downloaded swarmer in
-          c.client_downloaded <- c.client_downloaded ++ (
-            new_downloaded -- old_downloaded);
+          count_download c file (new_downloaded -- old_downloaded);
 (*
           if not (List.mem c.client_ip bb.block_contributors) then
             bb.block_contributors <- c.client_ip :: 
