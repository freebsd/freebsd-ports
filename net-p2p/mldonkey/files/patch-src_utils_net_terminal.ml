--- src/utils/net/terminal.ml.orig	2020-07-05 18:23:19 UTC
+++ src/utils/net/terminal.ml
@@ -183,7 +183,7 @@ module Output = struct
   let canal = List.assoc chan !chanmap in
   etat.chan <- Some (chan, canal);
   info (sprintf "connecte au canal '%s'" chan);
-  (* { | canal ALL } *)
+
        with Not_found -> (* pas encore de recepteur pour ce canal *)
   try (* on en cree un *)
     let serveur = nsrecord.get_loc chan in
