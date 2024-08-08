--- cargo-crates/lindera-unidic-0.31.0/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/lindera-unidic-0.31.0/build.rs
@@ -56,7 +56,7 @@ fn main() -> Result<(), Box<dyn Error>> {
         dummy_matrix_def.write_all(b"0 1 0\n")?;
     } else {
         // Source file path for build package
-        let source_path_for_build = Path::new(&build_dir).join(file_name);
+        let source_path_for_build = Path::new("%%DISTDIR%%").join(file_name);
 
         // Download source file to build directory
         if !source_path_for_build.exists() {
