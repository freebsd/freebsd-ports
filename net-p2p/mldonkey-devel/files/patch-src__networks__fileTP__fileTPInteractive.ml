--- ./src/networks/fileTP/fileTPInteractive.ml.orig	Mon Apr 10 16:16:13 2006
+++ ./src/networks/fileTP/fileTPInteractive.ml	Mon May 15 13:03:12 2006
@@ -90,11 +90,11 @@
         P.file_download_rate = file_download_rate file.file_file;
         P.file_chunks = (match file.file_swarmer with
           None -> "" | Some swarmer ->
-            CommonSwarming.verified_bitmap swarmer);
+            CommonSwarming.chunks_verified_bitmap swarmer);
         P.file_availability =
         [network.network_num,(match file.file_swarmer with
           None -> "" | Some swarmer ->
-            CommonSwarming.availability swarmer)];
+            CommonSwarming.chunks_availability swarmer)];
         P.file_format = FormatNotComputed 0;
         P.file_chunks_age = [|0|];
         P.file_age = file_age file;
