Index: cli/tools/jupyter/install.rs
--- cli/tools/jupyter/install.rs.orig
+++ cli/tools/jupyter/install.rs
@@ -51,7 +51,7 @@ pub fn install() -> Result<(), AnyError> {
   // https://jupyter-client.readthedocs.io/en/stable/kernels.html#kernel-specs
   // FIXME(bartlomieju): replace `current_exe` before landing?
   let json_data = json!({
-      "argv": [current_exe().unwrap().to_string_lossy(), "jupyter", "--kernel", "--conn", "{connection_file}"],
+      "argv": ["LOCALBASE/bin/deno", "jupyter", "--kernel", "--conn", "{connection_file}"],
       "display_name": "Deno",
       "language": "typescript",
   });
