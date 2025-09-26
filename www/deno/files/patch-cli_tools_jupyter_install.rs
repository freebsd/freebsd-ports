Index: cli/tools/jupyter/install.rs
--- cli/tools/jupyter/install.rs.orig
+++ cli/tools/jupyter/install.rs
@@ -1,6 +1,5 @@
 // Copyright 2018-2025 the Deno authors. MIT license.
 
-use std::env::current_exe;
 use std::io::Write;
 use std::path::Path;
 use std::path::PathBuf;
@@ -89,15 +88,11 @@ pub fn install(
   }
 
   let display_name = maybe_display_name.unwrap_or("Deno");
-  let current_exe_path = current_exe()
-    .context("Failed to get current executable path")?
-    .to_string_lossy()
-    .into_owned();
 
   // TODO(bartlomieju): add remaining fields as per
   // https://jupyter-client.readthedocs.io/en/stable/kernels.html#kernel-specs
   let json_data = json!({
-      "argv": [current_exe_path, "jupyter", "--kernel", "--conn", "{connection_file}"],
+      "argv": ["PREFIX/bin/deno", "jupyter", "--kernel", "--conn", "{connection_file}"],
       "display_name": display_name,
       "language": "typescript",
   });
