--- ./src/networks/donkey/donkeyInteractive.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/donkey/donkeyInteractive.ml	Sun May  7 06:39:10 2006
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
