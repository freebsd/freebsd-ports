--- pa_local.ml.orig	Mon Jun 25 11:20:33 2007
+++ pa_local.ml	Mon Jun 25 11:21:06 2007
@@ -14,10 +14,10 @@
 open Pcaml;
 
 value expr_of_patt p =
-  let loc = MLast.loc_of_patt p in
+  let _loc = MLast.loc_of_patt p in
   match p with
   [ <:patt< $lid:x$ >> -> <:expr< $lid:x$ >>
-  | _ -> Stdpp.raise_with_loc loc (Stream.Error "identifier expected") ]
+  | _ -> Stdpp.raise_with_loc _loc (Stream.Error "identifier expected") ]
 ;
 
 EXTEND
