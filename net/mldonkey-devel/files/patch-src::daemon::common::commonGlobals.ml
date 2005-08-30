--- src/daemon/common/commonGlobals.ml	28 Aug 2005 12:18:30 -0000	1.50
+++ src/daemon/common/commonGlobals.ml	29 Aug 2005 00:03:36 -0000
@@ -278,7 +278,7 @@
 
 let download_control = TcpBufferedSocket.create_read_bandwidth_controler
   "Download"
-    (!!max_hard_download_rate * 2048) (* TODO: changed from 1024 to 2048 because of bug *)
+    (!!max_hard_download_rate * 1024)
 
 
 let _ =
@@ -288,7 +288,7 @@
   option_hook max_hard_download_rate (fun _ ->
       let rate = !!max_hard_download_rate in
       TcpBufferedSocket.change_rate download_control
-        (rate * 2048)) (* TODO: changed from 1024 to 2048 because of bug *)
+        (rate * 1024))
 
 let udp_write_controler = UdpSocket.new_bandwidth_controler upload_control
 
Index: src/networks/bittorrent/bTClients.ml
===================================================================
RCS file: /cvsroot/mldonkey/mldonkey/src/networks/bittorrent/bTClients.ml,v
retrieving revision 1.48
