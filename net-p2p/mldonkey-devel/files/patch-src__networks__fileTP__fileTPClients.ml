--- ./src/networks/fileTP/fileTPClients.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/fileTP/fileTPClients.ml	Mon May 15 13:03:12 2006
@@ -188,8 +188,8 @@
                               lprintf "Current Block: "; CommonSwarming.print_block b;
                             end;
                           try
-                            let (x,y,r) = CommonSwarming.find_range up in
-
+                            let (x,y,r) = 
+			      CommonSwarming.find_range up min_range_size in
 (*                            lprintf "GOT RANGE:\n"; *)
                             if !verbose_swarming then CommonSwarming.print_uploaders swarmer;
 
@@ -269,7 +269,7 @@
                             let chunks = [ Int64.zero, file_size file ] in
                             let up = CommonSwarming.register_uploader swarmer
                               (as_client c)
-                                (AvailableRanges chunks) in
+                                (AvailableIntervals chunks) in
                             d.download_uploader <- Some up
                       ) c.client_downloads;
 
