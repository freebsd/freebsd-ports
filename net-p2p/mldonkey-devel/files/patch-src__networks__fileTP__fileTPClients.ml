--- ./src/networks/fileTP/fileTPClients.ml.orig	Sat Apr  8 21:26:41 2006
+++ ./src/networks/fileTP/fileTPClients.ml	Sun May  7 06:39:10 2006
@@ -269,7 +269,7 @@
                             let chunks = [ Int64.zero, file_size file ] in
                             let up = CommonSwarming.register_uploader swarmer
                               (as_client c)
-                                (AvailableRanges chunks) in
+                                (AvailableIntervals chunks) in
                             d.download_uploader <- Some up
                       ) c.client_downloads;
 
