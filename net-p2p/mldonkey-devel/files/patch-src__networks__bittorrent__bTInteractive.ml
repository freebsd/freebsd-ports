--- ./src/networks/bittorrent/bTInteractive.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/bittorrent/bTInteractive.ml	Mon May 15 13:03:12 2006
@@ -279,7 +279,7 @@
 
       let chunks = (match file.file_swarmer with
             None -> "" | Some swarmer ->
-              CommonSwarming.verified_bitmap swarmer) in
+              CommonSwarming.chunks_verified_bitmap swarmer) in
 
       let header_list = [
         ( "1", "srh br ac", "Client number", "Num" ) ;
@@ -372,7 +372,7 @@
     None ->
       lprintf_nl () "verify_chunks: no swarmer to verify chunks"
   | Some swarmer ->
-      CommonSwarming.verify_all_chunks swarmer true
+      CommonSwarming.verify_all_chunks_immediately swarmer
 
 let remove_all_clients file =
   Hashtbl.clear file.file_clients; 
@@ -408,11 +408,11 @@
     P.file_names = [file.file_name, P.noips()];
     P.file_chunks = (match file.file_swarmer with
         None -> "" | Some swarmer ->
-          CommonSwarming.verified_bitmap swarmer);
+          CommonSwarming.chunks_verified_bitmap swarmer);
     P.file_availability =
     [network.network_num,(match file.file_swarmer with
           None -> "" | Some swarmer ->
-            CommonSwarming.availability swarmer)];
+            CommonSwarming.chunks_availability swarmer)];
 
     P.file_chunks_age = last_seen;
     P.file_uids = [Uid.create (BTUrl file.file_id)];
