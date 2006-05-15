--- ./src/networks/fasttrack/fasttrackGlobals.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/fasttrack/fasttrackGlobals.ml	Mon May 15 13:03:12 2006
@@ -298,7 +298,7 @@
     }
   in
   incr search_num;
-  let kernel = CommonSwarming.create_swarmer file_temp file_size min_range_size in
+  let kernel = CommonSwarming.create_swarmer file_temp file_size in
   let swarmer = CommonSwarming.create kernel (as_file file)
       file_chunk_size in
   file.file_swarmer <- Some swarmer;
