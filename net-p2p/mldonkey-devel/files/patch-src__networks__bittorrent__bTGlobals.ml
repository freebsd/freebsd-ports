--- ./src/networks/bittorrent/bTGlobals.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/bittorrent/bTGlobals.ml	Mon May 15 13:03:12 2006
@@ -150,9 +150,9 @@
       (match c.client_block with
           None -> true
         | Some b ->
-            let block_num = CommonSwarming.block_num swarmer b in
-            let bitmap = CommonSwarming.verified_bitmap swarmer in
-            bitmap.[block_num] <> '3')
+            let chunk_num = CommonSwarming.block_chunk_num swarmer b in
+            let bitmap = CommonSwarming.chunks_verified_bitmap swarmer in
+            bitmap.[chunk_num] <> '3')
     in
     if must_send then
       begin
@@ -252,8 +252,7 @@
       else
         set_trackers file [t.torrent_announce];
       if file_state <> FileShared then begin
-          let kernel = CommonSwarming.create_swarmer file_temp (file_size file)
-            (min max_range_len file.file_piece_size) in
+          let kernel = CommonSwarming.create_swarmer file_temp (file_size file) in
           let swarmer = CommonSwarming.create kernel (as_file file)
             file.file_piece_size in
           file.file_swarmer <- Some swarmer;
