--- cargo-crates/xcb-0.8.2/build.rs.orig	2025-05-05 10:26:31 UTC
+++ cargo-crates/xcb-0.8.2/build.rs
@@ -64,13 +64,13 @@ fn main() {
 
         if ref_mtime > src_file_mtime || ref_mtime > ffi_file_mtime {
 
-            let status = Command::new("python3")
+            let status = Command::new("%%PYTHON_CMD%%")
                     .arg(&r_client)
                     .arg("-o").arg(&src_dir)
                     .arg(&xml_file)
                     .env("PYTHONHASHSEED", "0")
                     .status()
-                    .expect("Unable to find build dependency python3");
+                    .expect("Unable to find build dependency %%PYTHON_CMD%%");
             if !status.success() {
                 panic!("processing of {} returned non-zero ({})",
                     xml_file.display(), status.code().unwrap());
