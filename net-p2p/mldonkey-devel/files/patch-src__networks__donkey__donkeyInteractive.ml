--- ./src/networks/donkey/donkeyInteractive.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/donkey/donkeyInteractive.ml	Mon May 15 13:03:12 2006
@@ -507,7 +507,7 @@
   match file.file_swarmer with
     None -> ()
   | Some swarmer ->
-      CommonSwarming.verify_all_chunks swarmer false
+      CommonSwarming.verify_all_chunks swarmer
 
   (*
   if file.file_chunks <> [||] then
@@ -613,7 +613,7 @@
   match file.file_swarmer with
     None -> ()
   | Some swarmer ->
-      CommonSwarming.verify_all_chunks swarmer true
+      CommonSwarming.verify_all_chunks_immediately swarmer
 
 let register_commands list =
   register_commands
@@ -1044,13 +1044,13 @@
             P.file_chunks = 
                   (match file.file_swarmer with
                    | None -> "" 
-                   | Some swarmer -> CommonSwarming.verified_bitmap swarmer);
+                   | Some swarmer -> CommonSwarming.chunks_verified_bitmap swarmer);
             P.file_availability =
               [
                 network.network_num,
                 (match file.file_swarmer with
                   | None -> "" 
-                  | Some swarmer -> CommonSwarming.availability swarmer)
+                  | Some swarmer -> CommonSwarming.chunks_availability swarmer)
               ];
             P.file_format = file.file_format;
             P.file_chunks_age = last_seen;
@@ -1305,7 +1305,7 @@
       let chunks =
       (match file.file_swarmer with
        None -> "" | Some swarmer ->
-       CommonSwarming.verified_bitmap swarmer)
+       CommonSwarming.chunks_verified_bitmap swarmer)
       in
 
       html_mods_table_header buf "sourcesTable" "sources al" ([
