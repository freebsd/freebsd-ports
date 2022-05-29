--- cargo-crates/lindera-ipadic-0.12.6/build.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/lindera-ipadic-0.12.6/build.rs
@@ -25,7 +25,7 @@ fn main() -> Result<(), Box<dyn Error>> {
     let file_name = "mecab-ipadic-2.7.0-20070801.tar.gz";
 
     // MeCab IPADIC directory
-    let input_dir = Path::new(&build_dir).join("mecab-ipadic-2.7.0-20070801");
+    let input_dir = Path::new("%%WRKDIR%%").join("mecab-ipadic-2.7.0-20070801");
 
     // Lindera IPADIC directory
     let output_dir = Path::new(&build_dir).join("lindera-ipadic");
@@ -50,35 +50,6 @@ fn main() -> Result<(), Box<dyn Error>> {
         File::create(input_dir.join("unk.def"))?;
         let mut dummy_matrix_def = File::create(input_dir.join("matrix.def"))?;
         dummy_matrix_def.write_all(b"0 1 0\n")?;
-    } else {
-        // Source file path for build package
-        let source_path_for_build = Path::new(&build_dir).join(&file_name);
-
-        // Download source file to build directory
-        if !source_path_for_build.exists() {
-            // copy(&source_path, &source_path_for_build)?;
-            let tmp_path = Path::new(&build_dir).join(file_name.to_owned() + ".download");
-
-            // Download a tarball
-            let download_url =
-                "http://jaist.dl.sourceforge.net/project/mecab/mecab-ipadic/2.7.0-20070801/mecab-ipadic-2.7.0-20070801.tar.gz";
-            let resp = ureq::get(download_url).call()?;
-            let mut dest = File::create(&tmp_path)?;
-
-            io::copy(&mut resp.into_reader(), &mut dest)?;
-            dest.flush()?;
-
-            rename(tmp_path, &source_path_for_build).expect("Failed to rename temporary file");
-        }
-
-        // Decompress a tarball
-        let mut tar_gz = File::open(&source_path_for_build)?;
-        let mut buffer = Vec::new();
-        tar_gz.read_to_end(&mut buffer)?;
-        let cursor = Cursor::new(buffer);
-        let gzdecoder = GzDecoder::new(cursor);
-        let mut archive = Archive::new(gzdecoder);
-        archive.unpack(&build_dir)?;
     }
 
     // Build a dictionary
