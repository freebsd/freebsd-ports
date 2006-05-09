--- ./src/networks/bittorrent/bTInteractive.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/bittorrent/bTInteractive.ml	Sun May  7 06:39:10 2006
@@ -372,7 +372,7 @@
     None ->
       lprintf_nl () "verify_chunks: no swarmer to verify chunks"
   | Some swarmer ->
-      CommonSwarming.verify_all_chunks swarmer true
+      CommonSwarming.verify_all_chunks_immediately swarmer
 
 let remove_all_clients file =
   Hashtbl.clear file.file_clients; 
