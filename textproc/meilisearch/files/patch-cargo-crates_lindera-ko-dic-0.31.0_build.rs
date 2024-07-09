--- cargo-crates/lindera-ko-dic-0.31.0/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/lindera-ko-dic-0.31.0/build.rs
@@ -40,10 +40,7 @@ fn main() -> Result<(), Box<dyn Error>> {
         let mut dummy_dict_csv = File::create(input_dir.join("dummy_dict.csv"))?;
         dummy_dict_csv.write_all(
             &UTF_8
-                .encode(
-                    "테스트,1785,3543,4721,NNG,행위,F,테스트,*,*,*,*\n",
-                    EncoderTrap::Ignore,
-                )
+                .encode("테스트,1785,3543,4721,NNG,행위,F,테스트,*,*,*,*\n", EncoderTrap::Ignore)
                 .unwrap(),
         )?;
 
@@ -52,7 +49,7 @@ fn main() -> Result<(), Box<dyn Error>> {
         dummy_matrix_def.write_all(b"0 1 0\n")?;
     } else {
         // Source file path for build package
-        let source_path_for_build = Path::new(&build_dir).join(file_name);
+        let source_path_for_build = Path::new("%%DISTDIR%%").join(file_name);
 
         // Download source file to build directory
         if !source_path_for_build.exists() {
