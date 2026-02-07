--- vendor/ppxlib_jane-33fc3e4bd54ea4e3292d4d32936a46349c043fec/src/shim.ml.orig	2024-11-19 19:45:47 UTC
+++ vendor/ppxlib_jane-33fc3e4bd54ea4e3292d4d32936a46349c043fec/src/shim.ml
@@ -618,7 +618,7 @@ module Signature_item_desc = struct
     | Psig_modtypesubst a -> Psig_modtypesubst a
     | Psig_open a -> Psig_open a
     | Psig_include (a, b) ->
-      if List.is_empty b
+      if (match b with [] -> true | _ -> false)
       then Psig_include a
       else
         failwith
