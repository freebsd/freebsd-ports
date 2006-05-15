--- ./src/networks/bittorrent/bTComplexOptions.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/bittorrent/bTComplexOptions.ml	Mon May 15 13:03:12 2006
@@ -210,7 +210,7 @@
   (match file.file_swarmer with
       None -> ()
     | Some swarmer ->
-        CommonSwarming.value_to_swarmer swarmer assocs;
+        CommonSwarming.value_to_frontend swarmer assocs;
   );
 
 (*
@@ -262,7 +262,7 @@
     match file.file_swarmer with
       None -> assocs
     | Some swarmer ->
-        CommonSwarming.swarmer_to_value swarmer assocs
+        CommonSwarming.frontend_to_value swarmer assocs
   with
     e ->
       lprintf_nl () "exception %s in file_to_value"
