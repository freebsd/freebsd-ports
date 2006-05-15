--- ./src/networks/donkey/donkeyComplexOptions.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/donkey/donkeyComplexOptions.ml	Mon May 15 13:03:12 2006
@@ -297,7 +297,7 @@
   (match file.file_swarmer with
       None -> ()
     | Some swarmer ->
-        CommonSwarming.value_to_swarmer swarmer assocs;
+        CommonSwarming.value_to_frontend swarmer assocs;
         CommonSwarming.set_verifier swarmer (if md4s = [||] then
             VerificationNotAvailable
           else
@@ -321,7 +321,7 @@
   match file.file_swarmer with
     None -> fields
     | Some swarmer ->
-        CommonSwarming.swarmer_to_value swarmer fields
+        CommonSwarming.frontend_to_value swarmer fields
   in
   fields
     
