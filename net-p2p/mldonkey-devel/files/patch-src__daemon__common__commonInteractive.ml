--- ../mldonkey.orig/src/daemon/common/commonInteractive.ml	Fri Dec  2 10:08:04 2005
+++ src/daemon/common/commonInteractive.ml	Fri Dec  9 21:23:18 2005
@@ -106,7 +106,7 @@
   let file_id = Filename.basename temp_name in
   let size = Int64.to_string (file_size file) in
   let duration =
-    Date.time_to_string_long ((BasicSocket.last_time ()) - info.G.file_age)
+    string_of_int ((BasicSocket.last_time ()) - info.G.file_age)
   in
   let network = network_find_by_num info.G.file_network in
   let filename = Filename.basename new_name in
@@ -117,6 +117,7 @@
         (Int64.to_string (file_size file))
         (Md4.to_string info.G.file_md4)
   in
+  begin try
   MlUnix.fork_and_exec !!file_completed_cmd
       [|  (* keep those for compatibility *)
       "";
@@ -133,6 +134,10 @@
 	    ("INCOMING",  incoming);
 	    ("NETWORK",   network.network_name);
 	    ("ED2K_HASH", ed2k_hash)]
+  with e -> 
+      lprintf_nl "[cInt] Exception %s while executing %s"
+        (Printexc2.to_string e) !!file_completed_cmd
+  end
 
 (********
 These two functions 'file_commit' and 'file_cancel' should be the two only
