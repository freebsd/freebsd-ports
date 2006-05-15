--- ./src/networks/gnutella/gnutellaInteractive.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/gnutella/gnutellaInteractive.ml	Mon May 15 13:03:12 2006
@@ -252,7 +252,7 @@
           match file.file_ttr with
             None -> failwith "No TTR for verification"
           | Some ttt ->
-              CommonSwarming.verify_all_chunks swarmer true  
+              CommonSwarming.verify_all_chunks_immediately swarmer
   );  
   
   file_ops.op_file_recover <- (fun file ->
@@ -289,11 +289,11 @@
         
          P.file_chunks = (match file.file_swarmer with
              None -> "" | Some swarmer ->
-               CommonSwarming.verified_bitmap swarmer);
+               CommonSwarming.chunks_verified_bitmap swarmer);
         P.file_availability =   [network.network_num,
            (match file.file_swarmer with
            None -> "" | Some swarmer ->
-                 CommonSwarming.availability swarmer)];
+                 CommonSwarming.chunks_availability swarmer)];
         
         P.file_chunks_age = [|0|];
         P.file_last_seen = BasicSocket.last_time ();
