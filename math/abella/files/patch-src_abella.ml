--- src/abella.ml.orig	2024-05-21 12:02:44 UTC
+++ src/abella.ml
@@ -877,8 +877,7 @@ let () =
 
   let em =
     let doc = "Does nothing; use abella_dep instead." in
-    let deprecated = "The -M flag is deprecated and does nothing; use abella_dep instead" in
-    Arg.(value @@ flag @@ info ["M"] ~doc ~deprecated)
+    Arg.(value @@ flag @@ info ["M"] ~doc)
   in
 
   let file =
@@ -897,9 +896,8 @@ let () =
       `S Manpage.s_bugs ;
       `P "File bug reports on <$(b,https://github.com/abella-prover/abella/issues)>" ;
     ] in
-    let info = Cmd.info "abella" ~doc ~man ~exits:[] ~version:Version.version in
-    Cmd.v info @@ Term.(const abella_main $ flags $ switch $ output $ compiled $ annotate $ norec $ em $ file)
+    let info = Term.info "abella" ~doc ~man ~exits:[] ~version:Version.version in
+    Term.(const abella_main $ flags $ switch $ output $ compiled $ annotate $ norec $ em $ file), info
   in
-
-  Stdlib.exit (Cmd.eval' cmd)
+  Term.exit @@ Term.eval cmd
 ;;
