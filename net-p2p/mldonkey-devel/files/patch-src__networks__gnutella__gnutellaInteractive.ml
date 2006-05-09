--- ./src/networks/gnutella/gnutellaInteractive.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/gnutella/gnutellaInteractive.ml	Sun May  7 06:39:10 2006
@@ -252,7 +252,7 @@
           match file.file_ttr with
             None -> failwith "No TTR for verification"
           | Some ttt ->
-              CommonSwarming.verify_all_chunks swarmer true  
+              CommonSwarming.verify_all_chunks_immediately swarmer
   );  
   
   file_ops.op_file_recover <- (fun file ->
