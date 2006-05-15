--- ./src/networks/fileTP/fileTPGlobals.ml.orig	Mon Apr 10 16:16:13 2006
+++ ./src/networks/fileTP/fileTPGlobals.ml	Mon May 15 13:03:12 2006
@@ -120,7 +120,7 @@
       in
       file.file_file.impl_file_size <- size;
       let file_temp = Unix32.filename (file_fd file) in
-      let kernel = CommonSwarming.create_swarmer file_temp size min_range_size in
+      let kernel = CommonSwarming.create_swarmer file_temp size in
       let swarmer = CommonSwarming.create kernel (as_file file)
           file_chunk_size in
       file.file_swarmer <- Some swarmer;
