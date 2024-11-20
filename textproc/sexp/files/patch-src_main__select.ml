--- src/main_select.ml.orig	2024-05-07 18:46:09 UTC
+++ src/main_select.ml
@@ -77,12 +77,13 @@ let remove_duplicates_flag =
 ;;
 
 let remove_duplicates_flag =
+  let list_stable_dedup = List.stable_dedup_staged ~compare:Sexp.compare in
   let open Command.Param in
   flag
     ~doc:" remove duplicate outputs from each PROGRAM"
     "remove-dupes"
     (map_flag no_arg ~f:(fun arg ->
-       Option.some_if arg (List.stable_dedup ~compare:Sexp.compare)))
+       Option.some_if arg (unstage list_stable_dedup)))
 ;;
 
 let drop_flag =
