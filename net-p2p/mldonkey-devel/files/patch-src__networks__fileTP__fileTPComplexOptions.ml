--- ./src/networks/fileTP/fileTPComplexOptions.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/fileTP/fileTPComplexOptions.ml	Mon May 15 13:03:12 2006
@@ -84,7 +84,7 @@
   (match file.file_swarmer with
       None -> ()
     | Some swarmer ->
-        CommonSwarming.value_to_swarmer swarmer assocs;
+        CommonSwarming.value_to_frontend swarmer assocs;
   );
 
   (try
@@ -118,7 +118,7 @@
   match file.file_swarmer with
     None -> assocs
   | Some swarmer ->
-      CommonSwarming.swarmer_to_value swarmer assocs
+      CommonSwarming.frontend_to_value swarmer assocs
 
 let old_files =
   define_option fileTP_section ["old_urls"]
