diff --git a/src/copy.ml b/src/copy.ml
index b9e10f6..19c2370 100644
--- copy.ml
+++ copy.ml
@@ -1004,7 +1004,14 @@ let recursively fspathFrom pathFrom fspathTo pathTo =
         let ch = Os.childrenOf fspathFrom pFrom in
         Safelist.iter
           (fun n -> copy (Path.child pFrom n) (Path.child pTo n)) ch
-    | `ABSENT -> assert false in
+    | `ABSENT ->
+        (* BCP 4/16: Was "assert false", but this causes unison to
+           crash when (1) the copyonconflict preference is used, (2) 
+           there is a conflict between a deletion and a change, and
+           (3) the change is propagated on top of the deletion.  Seems
+           better to silently ignore the copy request. *)
+        ()
+    in
   debug (fun () -> Util.msg "  Copying recursively %s / %s\n"
     (Fspath.toDebugString fspathFrom) (Path.toString pathFrom));
   copy pathFrom pathTo;
