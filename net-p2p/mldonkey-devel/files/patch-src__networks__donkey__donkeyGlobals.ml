--- ./src/networks/donkey/donkeyGlobals.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/donkey/donkeyGlobals.ml	Mon May 15 13:03:12 2006
@@ -397,7 +397,7 @@
       (match file_state with
           FileShared -> ()
         | _ ->
-            let kernel = CommonSwarming.create_swarmer file_diskname file_size zone_size in
+            let kernel = CommonSwarming.create_swarmer file_diskname file_size in
             let swarmer = CommonSwarming.create kernel (as_file file) block_size
             in
             file.file_swarmer <- Some swarmer;
