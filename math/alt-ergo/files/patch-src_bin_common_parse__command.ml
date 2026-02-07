--- src/bin/common/parse_command.ml.orig	2024-05-13 13:12:16 UTC
+++ src/bin/common/parse_command.ml
@@ -37,6 +37,10 @@ exception Exit_parse_command of int
 (* Exception used to exit with corresponding retcode *)
 exception Exit_parse_command of int
 
+let compat_FREEBSD =
+  let ok r = `Ok r and error r = `Error r in
+  fun parser s -> Result.fold ~ok ~error @@ parser s
+
 let instantiation_heuristic_parser = function
   | "normal" -> Ok INormal
   | "auto" -> Ok IAuto
@@ -637,7 +641,7 @@ let parse_execution_opt =
         Ok ()
       with
         Errors.Error e ->
-        Error (Format.asprintf "%a" Errors.report e)
+        Error (`Msg (Format.asprintf "%a" Errors.report e))
     in
     let load_parsers verbose paths =
       List.fold_left
@@ -651,7 +655,7 @@ let parse_execution_opt =
            info ["add-parser"] ~docs ~doc)
     in
     let term = Term.(const load_parsers $ get_verbose_t $ arg) in
-    Term.term_result' term
+    Term.term_result term
   in
 
   let preludes =
@@ -687,7 +691,7 @@ let parse_execution_opt =
               p)
     in
     let prelude =
-      Arg.(conv' (parse_prelude, conv_printer string))
+      Arg.(pconv (compat_FREEBSD parse_prelude, conv_printer string))
     in
     let doc =
       "Add a file that will be loaded as a prelude. The command is \
@@ -948,7 +952,7 @@ let parse_output_opt =
             Error ("Args parsing error: unkown SAT solver " ^ sat_solver)
 
         in
-        Arg.(conv' (parse, Util.pp_sat_solver))
+        Arg.(pconv (compat_FREEBSD parse, Util.pp_sat_solver))
       in
       let default, sum_up = "CDCL-Tableaux", "satML" in
       let doc = Format.sprintf
@@ -969,11 +973,13 @@ let parse_output_opt =
       | INone, Some sat_solver -> Ok sat_solver
       | _, (None | Some Util.Tableaux) -> Ok Tableaux
       | _, Some sat_solver ->
+
+      Result.map_error (fun str -> `Msg str) @@
         Fmt.error
           "solver '%a' does not suppot model generation"
           Util.pp_sat_solver sat_solver
     in
-    Term.term_result' @@
+    Term.term_result @@
     Term.(const mk_sat_solver $ sat_solver_arg $ interpretation)
   in
 
@@ -1279,7 +1285,7 @@ let parse_theory_opt =
             "'inequalities' reasoner (FM module)";
           Ok ()
         with Errors.Error e ->
-          Error (Format.asprintf "%a" Errors.report e)
+          Error (`Msg (Format.asprintf "%a" Errors.report e))
     in
     let arg =
       let doc =
@@ -1290,7 +1296,7 @@ let parse_theory_opt =
     let term =
       Term.(const load_inequalities_plugin $ Debug.light_flag_term $ arg)
     in
-    Term.term_result' term
+    Term.term_result term
   in
 
   let no_contracongru =
@@ -1328,8 +1334,7 @@ let parse_theory_opt =
   let use_fpa =
     let doc = "Floating-point builtins are always enabled and this option has
       no effect anymore. It will be removed in a future version." in
-    let deprecated = "this option is always enabled" in
-    Arg.(value & flag & info ["use-fpa"] ~docs ~doc ~deprecated) in
+    Arg.(value & flag & info ["use-fpa"] ~docs ~doc) in
 
   let theories =
     let theory_enum =
@@ -1368,15 +1373,13 @@ let parse_theory_opt =
       let disable_adts =
         let doc = "Disable Algebraic Datatypes theory. Deprecated alias for
         `--disable-theories adt`." in
-        let deprecated = "use `--disable-theories ac` instead." in
-        Arg.(value & flag & info ["disable-adts"] ~docs ~doc ~deprecated)
+        Arg.(value & flag & info ["disable-adts"] ~docs ~doc)
       in
       let no_ac =
         let doc = "Disable the AC theory of Associative and \
                    Commutative function symbols. Deprecated alias for
                   `--disable-theories ac`." in
-        let deprecated = "use `--disable-theories ac` instead" in
-        Arg.(value & flag & info ["no-ac"] ~docs ~doc ~deprecated)
+        Arg.(value & flag & info ["no-ac"] ~docs ~doc)
       in
       let mk_disable_theories disable_theories disable_adts no_ac =
         let open Theories in
@@ -1450,16 +1453,13 @@ let parse_fmt_opt =
           models and unsat cores. Possible values are %s."
         (Arg.doc_alts ["stdout"; "stderr"; "<filename>"])
     in
-    let deprecated =
-      "this option is deprecated. Please use --regular-output."
-    in
     let regular_output =
-      Arg.(value & opt (some' string) None & info ["regular-output"] ~docs
+      Arg.(value & opt (some string) None & info ["regular-output"] ~docs
              ~doc ~docv)
     in
     let std_formatter =
-      Arg.(value & opt (some' string) None  & info ["std-formatter"]
-             ~deprecated ~docs ~docv)
+      Arg.(value & opt (some string) None  & info ["std-formatter"]
+             ~docs ~docv)
     in
     Term.(const (merge_formatters "stdout") $ regular_output $ std_formatter)
   in
@@ -1471,16 +1471,13 @@ let parse_fmt_opt =
          warning informations. Possible values are %s."
         (Arg.doc_alts ["stdout"; "stderr"; "<filename>"])
     in
-    let deprecated =
-      "this option is deprecated. Please use --diagnostic-output."
-    in
     let diagnostic_output =
-      Arg.(value & opt (some' string) None & info ["diagnostic-output"] ~docs
+      Arg.(value & opt (some string) None & info ["diagnostic-output"] ~docs
              ~doc ~docv)
     in
     let err_formatter =
-      Arg.(value & opt (some' string) None & info ["err-formatter"]
-             ~deprecated ~docs ~docv)
+      Arg.(value & opt (some string) None & info ["err-formatter"]
+             ~docs ~docv)
     in
     Term.(const (merge_formatters "stderr") $ diagnostic_output $ err_formatter)
   in
@@ -1498,9 +1495,9 @@ let main =
     Arg.(value & pos ~rev:true 0 (some file) None & i) in
 
   let doc = "Execute Alt-Ergo on the given file." in
-  let exits = Cmd.Exit.defaults in
-  let to_exit = Cmd.Exit.info ~doc:"on timeout errors" ~max:142 142 in
-  let dft_errors = Cmd.Exit.info ~doc:"on default errors" ~max:1 1 in
+  let exits = Term.default_exits in
+  let to_exit = Term.exit_info ~doc:"on timeout errors" ~max:142 142 in
+  let dft_errors = Term.exit_info ~doc:"on default errors" ~max:1 1 in
   let exits = to_exit :: dft_errors :: exits in
 
   (* Specify the order in which the sections should appear
@@ -1560,17 +1557,17 @@ let main =
               ))
   in
   let info =
-    Cmd.info "alt-ergo" ~version:Version._version ~doc ~exits ~man
+    Term.info "alt-ergo" ~version:Version._version ~doc ~exits ~man
   in
-  Cmd.v info term
+  term, info
 
 let parse_cmdline_arguments () =
   at_exit Options.Output.close_all;
-  let r = Cmd.eval_value main in
+  let r = Term.eval main in
   match r with
-  | Ok `Ok true -> ()
-  | Ok `Ok false -> raise (Exit_parse_command 0)
-  | Ok `Version | Ok `Help -> exit 0
-  | Error `Parse -> exit Cmd.Exit.cli_error
-  | Error `Term -> exit Cmd.Exit.internal_error
-  | Error `Exn -> exit Cmd.Exit.internal_error
+  | `Ok true -> ()
+  | `Ok false -> raise (Exit_parse_command 0)
+  | `Version | `Help -> exit 0
+  | `Error `Parse -> exit Term.exit_status_cli_error
+  | `Error `Term -> exit Term.exit_status_internal_error
+  | `Error `Exn -> exit Term.exit_status_internal_error
