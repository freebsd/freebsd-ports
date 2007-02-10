--- ./src/networks/donkey/donkeyFiles.ml.orig	Tue Nov 21 20:34:10 2006
+++ ./src/networks/donkey/donkeyFiles.ml	Sat Feb 10 07:00:40 2007
@@ -123,7 +123,7 @@
 (*      lprintf "send_client_block\n"; *)
       if per_client > 0 && CommonUploads.can_write_len sock max_msg_size then
         match c.client_upload with
-        | Some ({ up_chunks = _ :: chunks } as up)  ->
+        | Some ({ up_chunks = current_chunk :: chunks } as up)  ->
             if up.up_file.file_shared = None then begin
 (* Is there a message to warn that a file is not shared anymore ? *)
                 c.client_upload <- None;
@@ -134,16 +134,17 @@
             if max_len <= msg_block_size_int then
 (* last block from chunk *)
               begin
+                send_small_block c sock up.up_file up.up_pos max_len;
                 if !verbose_upload then
                     lprintf_nl "End of chunk (%d) %Ld %s" max_len up.up_end_chunk (file_best_name up.up_file);
-                send_small_block c sock up.up_file up.up_pos max_len;
+		up.up_flying_chunks <- up.up_flying_chunks @ [current_chunk];
                 up.up_chunks <- chunks;
                 let per_client = per_client - max_len in
                 match chunks with
-                  [] -> 
+		| [] -> 
                     if !verbose_upload then
-                        lprintf_nl "NO CHUNKS";
-                    c.client_upload <- None;
+                        lprintf_nl "NO MORE CHUNKS";
+		    up.up_waiting <- false;
                 | (begin_pos, end_pos) :: _ ->
                     up.up_pos <- begin_pos;
                     up.up_end_chunk <- end_pos;
@@ -168,10 +169,10 @@
           let size = min max_msg_size size in
           send_client_block c sock size;
            (match c.client_upload with
-              None -> ()
-            | Some up ->
+            | Some ({ up_chunks = _ :: _ }) ->
                 if !CommonUploads.has_upload = 0 then
                   CommonUploads.ready_for_upload (as_client c)
+	    | _ -> ()
           )
       )
     let _ =
