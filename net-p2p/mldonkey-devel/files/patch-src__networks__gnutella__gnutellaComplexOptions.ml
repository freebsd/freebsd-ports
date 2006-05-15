--- ./src/networks/gnutella/gnutellaComplexOptions.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/gnutella/gnutellaComplexOptions.ml	Mon May 15 13:03:12 2006
@@ -140,7 +140,7 @@
   (match file.file_swarmer with
       None -> ()
     | Some swarmer ->
-        CommonSwarming.value_to_swarmer swarmer assocs;
+        CommonSwarming.value_to_frontend swarmer assocs;
         CommonSwarming.set_verifier swarmer (
           match file.file_ttr with
             None -> ForceVerification
@@ -183,7 +183,7 @@
 (*      "file_present_chunks", List
         (List.map (fun (i1,i2) -> 
             SmallList [int64_to_value i1; int64_to_value i2])
-        (CommonSwarming.present_chunks file.file_swarmer));
+        (CommonSwarming.present_intervals file.file_swarmer));
 *)  
     ]
   in
@@ -196,7 +196,7 @@
     match file.file_swarmer with
     None -> assocs 
   | Some swarmer ->
-      CommonSwarming.swarmer_to_value swarmer assocs
+      CommonSwarming.frontend_to_value swarmer assocs
       
 
   (*
