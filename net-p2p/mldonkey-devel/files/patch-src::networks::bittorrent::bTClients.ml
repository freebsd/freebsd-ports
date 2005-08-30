--- src/networks/bittorrent/bTClients.ml	15 Aug 2005 20:30:11 -0000	1.48
+++ src/networks/bittorrent/bTClients.ml	29 Aug 2005 00:42:36 -0000
@@ -763,13 +763,9 @@
               Int64Swarmer.downloaded swarmer in
 
             (*Update rate and amount of data received from client*)
-            c.client_downloaded <- c.client_downloaded ++
-              (new_downloaded -- old_downloaded);
+            count_download c file (new_downloaded -- old_downloaded);
             (* use len here with max_dr quickfix *)
             Rate.update c.client_downloaded_rate  (float_of_int len);
-            (* update the stats *)
-            let len64 = Int64.of_int len in
-            count_download c file len64;
             network_must_update network;
             if !verbose_msg_clients then
               (match c.client_ranges_sent with
@@ -1455,14 +1451,13 @@
           let file = c.client_file in
           let offset = pos ++ file.file_piece_size *.. num in
           c.client_allowed_to_write <- c.client_allowed_to_write -- len;
-          c.client_uploaded <- c.client_uploaded ++ len;
+          count_upload c file len;
           let len = Int64.to_int len in
           CommonUploads.consume_bandwidth len;
 (*          lprintf "Unix32.read: offset %Ld len %d\n" offset len; *)
           Unix32.read (file_fd file) offset upload_buffer 0 len;
           (* update upload rate from len bytes *)
-          (* will be reverted to len instead of len / 2 when rate bug will be fixed *)
-          Rate.update c.client_upload_rate  (float_of_int (len / 2));
+          Rate.update c.client_upload_rate  (float_of_int len);
           file.file_uploaded <- file.file_uploaded ++ (Int64.of_int len);
           let _ =
             (* update stats *)
@@ -1477,9 +1472,6 @@
           in
 (*          lprintf "sending piece\n"; *)
           send_client c (Piece (num, pos, upload_buffer, 0, len));
-          (* update stats *)
-          let uploaded = Int64.of_int len in
-          count_upload c file uploaded;
           network_must_update network;
           iter_upload sock c
         end else
Index: src/networks/donkey/donkeyOneFile.ml
===================================================================
RCS file: /cvsroot/mldonkey/mldonkey/src/networks/donkey/donkeyOneFile.ml,v
retrieving revision 1.26
