--- ./src/networks/donkey/donkeyClient.ml.orig	Sun Nov 26 14:36:06 2006
+++ ./src/networks/donkey/donkeyClient.ml	Sat Feb 10 07:00:40 2007
@@ -442,15 +442,17 @@
   
 let new_chunk up begin_pos end_pos =
   if begin_pos <> end_pos then
-    let pair = (begin_pos, end_pos) in
-    (match up.up_chunks with
-        [] ->
+    let chunk = (begin_pos, end_pos) in
+    (* the zone requested is already "in the pipe" *)
+    if not (List.mem chunk up.up_flying_chunks) then
+      match up.up_chunks with
+      | [] ->
           up.up_pos <- begin_pos;
           up.up_end_chunk <- end_pos;
-          up.up_chunks <- [pair];
-      | chunks ->
-          if not (List.mem pair chunks) then
-            up.up_chunks <- chunks @ [pair])
+          up.up_chunks <- [chunk];
+      | up_chunks ->
+          if not (List.mem chunk up_chunks) then
+            up.up_chunks <- up_chunks @ [chunk]
   
 let identify_client_brand c =
   if c.client_brand = Brand_unknown then
@@ -2039,13 +2041,21 @@
         set_rtimeout sock !!upload_timeout;
         
         let up, waiting = match c.client_upload with
-            Some ({ up_file = f } as up) when f == file ->  up, up.up_waiting
+          | Some ({ up_file = f } as up) when f == file ->
+	      (* zones are received in the order they're sent, so we
+		 know that the oldest of the zones "in fly" must have
+		 been received when this QueryBlockReq was sent *)
+	      (match up.up_flying_chunks with
+	       | [] -> () 
+	       | _ :: q -> up.up_flying_chunks <- q);
+	      up, up.up_waiting
           | Some old_up ->
               {
                 up_file = file;
                 up_pos = Int64.zero;
                 up_end_chunk = Int64.zero;
                 up_chunks = [];
+		up_flying_chunks = [];
                 up_waiting = old_up.up_waiting;
               }, old_up.up_waiting
           | _ ->
@@ -2054,6 +2064,7 @@
                 up_pos = Int64.zero;
                 up_end_chunk = Int64.zero;
                 up_chunks = [];
+		up_flying_chunks = [];
                 up_waiting = false;
               }, false
         in
@@ -2141,12 +2152,12 @@
 let init_client sock c =
   set_handler sock WRITE_DONE (fun s ->
       match c.client_upload with
-        None -> ()
-      | Some up ->
+      | Some ({ up_chunks = _ :: _ } as up) ->
           if not up.up_waiting && !CommonUploads.has_upload = 0 then begin
               up.up_waiting <- true;
               CommonUploads.ready_for_upload (as_client c)
             end
+      | _ -> ()
   );
 (*
   set_handler sock (BASIC_EVENT RTIMEOUT) (fun s ->
