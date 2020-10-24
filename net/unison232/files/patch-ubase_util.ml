--- ubase/util.ml.orig	2009-05-02 02:31:27 UTC
+++ ubase/util.ml
@@ -71,7 +71,7 @@ let set_infos s =
   if s <> !infos then begin clear_infos (); infos := s; show_infos () end
 
 let msg f =
-  clear_infos (); Uprintf.eprintf (fun () -> flush stderr; show_infos ()) f
+  clear_infos (); Printf.kfprintf (fun c -> flush c; show_infos ()) stderr f
 
 let msg : ('a, out_channel, unit) format -> 'a = msg
 
