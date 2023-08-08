--- cargo-crates/lindera-ipadic-0.23.0/build.rs.orig	2023-06-07 21:46:22 UTC
+++ cargo-crates/lindera-ipadic-0.23.0/build.rs
@@ -26,7 +26,7 @@ fn main() -> Result<(), Box<dyn Error>> {
     let build_dir = env::var_os("OUT_DIR").unwrap(); // ex) target/debug/build/<pkg>/out
 
     // MeCab IPADIC directory
-    let input_dir = Path::new(&build_dir).join("mecab-ipadic-2.7.0-20070801");
+    let input_dir = Path::new("%%WRKDIR%%").join("mecab-ipadic-2.7.0-20070801");
 
     if std::env::var("DOCS_RS").is_ok() {
         // Create directory for dummy input directory for build docs
@@ -51,24 +51,6 @@ fn main() -> Result<(), Box<dyn Error>> {
         File::create(input_dir.join("unk.def"))?;
         let mut dummy_matrix_def = File::create(input_dir.join("matrix.def"))?;
         dummy_matrix_def.write_all(b"0 1 0\n")?;
-    } else {
-        // Resources directory
-        let resources_dir_path = Path::new("resources");
-
-        // Dictionary file name
-        let dict_file_name = "mecab-ipadic-2.7.0-20070801.tar.gz";
-
-        // Source dictionary file path
-        let source_dict_file_path = resources_dir_path.join(dict_file_name);
-
-        // Decompress a tar.gz file
-        let mut tar_gz = File::open(source_dict_file_path)?;
-        let mut buffer = Vec::new();
-        tar_gz.read_to_end(&mut buffer)?;
-        let cursor = Cursor::new(buffer);
-        let gzdecoder = GzDecoder::new(cursor);
-        let mut archive = Archive::new(gzdecoder);
-        archive.unpack(&build_dir)?;
     }
 
     // Lindera IPADIC directory
