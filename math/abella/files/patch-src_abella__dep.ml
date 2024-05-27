--- src/abella_dep.ml.orig	2024-05-21 11:46:09 UTC
+++ src/abella_dep.ml
@@ -132,7 +132,7 @@ let () =
       `S Manpage.s_bugs ;
       `P "File bug reports on <$(b,https://github.com/abella-prover/abella/issues)>" ;
     ] in
-    let info = Cmd.info "abella_dep" ~doc ~man ~exits:[] in
-    Cmd.v info @@ Term.(const abella_dep $ conf $ files)
+    let info = Term.info "abella_dep" ~doc ~man ~exits:[] in
+    Term.(const abella_dep $ conf $ files), info
   in
-  exit (Cmd.eval cmd)
+  Term.exit @@ Term.eval cmd
