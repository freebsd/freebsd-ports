--- ./src/networks/gnutella/gnutellaClients.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/gnutella/gnutellaClients.ml	Mon May 15 13:03:12 2006
@@ -479,7 +479,7 @@
                   let chunks = [ Int64.zero, file_size file ] in
                   let up = CommonSwarming.register_uploader swarmer 
                       (as_client c)
-                    (AvailableRanges chunks) in
+                    (AvailableIntervals chunks) in
                   d.download_uploader <- Some up;
                   up                
               
@@ -536,7 +536,8 @@
 end;
   *)
                       try
-                        let (x,y,r) = CommonSwarming.find_range up in 
+                        let (x,y,r) = 
+			  CommonSwarming.find_range up (Int64.of_int (256 * 1024)) in 
                         
                         if !verbose_swarming then begin
                             lprintf "GOT RANGE:\n";
