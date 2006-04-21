--- ./src/networks/bittorrent/bTClients.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/networks/bittorrent/bTClients.ml	Thu Apr 20 11:04:03 2006
@@ -561,7 +561,7 @@
     match c.client_uploader with
       None ->
         let up = CommonSwarming.register_uploader swarmer (as_client c)
-          (AvailableRanges []) in
+          (AvailableIntervals []) in
         c.client_uploader <- Some up;
         up
     | Some up ->
