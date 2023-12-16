--- cargo-crates/lindera-unidic-0.27.1/build.rs.orig
+++ cargo-crates/lindera-unidic-0.27.1/build.rs
@@ -56,7 +56,7 @@
         dummy_matrix_def.write_all(b"0 1 0\n")?;
     } else {
         // Source file path for build package
-        let source_path_for_build = Path::new(&build_dir).join(file_name);
+        let source_path_for_build = Path::new("%%DISTDIR%%").join(file_name);
 
         // Download source file to build directory
         if !source_path_for_build.exists() {
