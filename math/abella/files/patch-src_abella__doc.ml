--- src/abella_doc.ml.orig	2024-05-21 12:00:44 UTC
+++ src/abella_doc.ml
@@ -261,13 +261,12 @@ let () =
         let ab1 = Filename.concat dir "abella" in
         let ab2 = Filename.concat dir "abella.exe" in
         if Sys.file_exists ab1 then ab1 else ab2 in
-      let env = Cmd.Env.info "ABELLA"
+      let env = Arg.env_var "ABELLA"
           ~doc:"Abella command to run (overriden by $(b,--abella))" in
       let doc = "Set the Abella command to $(docv)" in
       Arg.(value @@ opt string default @@
            info ["a" ; "abella"] ~doc ~env
-             ~docv:"CMD"
-             ~absent:"$(b,abella[.exe])")
+             ~docv:"CMD")
     in
     let verbose =
       let doc = "Verbose output" in
@@ -298,7 +297,8 @@ let () =
       `S Manpage.s_bugs ;
       `P "File bug reports on <$(b,https://github.com/abella-prover/abella/issues)>" ;
     ] in
-    let info = Cmd.info "abella_doc" ~doc ~man ~exits:[] in
-    Cmd.v info @@ Term.(const main $ conf $ files)
+    let info = Term.info "abella_doc" ~doc ~man ~exits:[] in
+    (Term.(const main $ conf $ files), info)
   in
-  exit (Cmd.eval cmd)
+  Term.exit @@ Term.eval cmd
+  (* exit (Cmd.eval cmd) *)
