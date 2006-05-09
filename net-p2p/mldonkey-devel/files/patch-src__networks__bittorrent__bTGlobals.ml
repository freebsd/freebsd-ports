--- ./src/networks/bittorrent/bTGlobals.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/bittorrent/bTGlobals.ml	Sun May  7 06:39:10 2006
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
