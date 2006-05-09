--- ./src/networks/gnutella/gnutellaComplexOptions.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/gnutella/gnutellaComplexOptions.ml	Sun May  7 06:39:10 2006
@@ -183,7 +183,7 @@
 (*      "file_present_chunks", List
         (List.map (fun (i1,i2) -> 
             SmallList [int64_to_value i1; int64_to_value i2])
-        (CommonSwarming.present_chunks file.file_swarmer));
+        (CommonSwarming.present_intervals file.file_swarmer));
 *)  
     ]
   in
