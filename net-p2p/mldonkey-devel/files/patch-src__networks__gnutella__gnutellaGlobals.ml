--- ./src/networks/gnutella/gnutellaGlobals.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/gnutella/gnutellaGlobals.ml	Thu Apr 20 11:04:04 2006
@@ -325,8 +325,7 @@
   in
   if !verbose then
     lprintf "SET SIZE : %Ld\n" file_size;
-  let kernel = CommonSwarming.create_swarmer file_temp file_size 
-      (Int64.of_int (256 * 1024))  in
+  let kernel = CommonSwarming.create_swarmer file_temp file_size in
   let swarmer = CommonSwarming.create kernel (as_file file) megabyte in
   CommonSwarming.set_verifier swarmer ForceVerification;
   
