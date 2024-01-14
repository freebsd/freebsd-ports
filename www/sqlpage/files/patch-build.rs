--- build.rs.orig	2023-12-10 14:43:17.000000000 +0100
+++ build.rs	2024-01-10 23:41:55.935212000 +0100
@@ -1,7 +1,7 @@
 use actix_rt::spawn;
-use futures_util::StreamExt;
 use libflate::gzip;
 use std::collections::hash_map::DefaultHasher;
+use std::fs;
 use std::fs::File;
 use std::hash::Hasher;
 use std::io::Read;
@@ -41,14 +41,16 @@
 }
 
 async fn process_input_file(path_out: &Path, original: File) {
-    let client = awc::Client::default();
     let mut outfile = gzip::Encoder::new(File::create(path_out).unwrap()).unwrap();
     for l in BufReader::new(original).lines() {
         let line = l.unwrap();
         if line.starts_with("/* !include https://") {
-            let url = line
-                .trim_start_matches("/* !include ")
+            let file_path = line
+                .trim_start_matches("/* !include https://cdn.jsdelivr.net/npm/")
                 .trim_end_matches(" */");
+            let contents = fs::read_to_string(file_path).expect("Failed to read data from file");
+            outfile.write_all(contents.as_bytes()).expect("Failed to write to file");
+            /*
             let mut resp = client.get(url).send().await.expect(
                 "We need to download external frontend dependencies to build the static frontend.",
             );
@@ -61,6 +63,7 @@
                     .write_all(&chunk)
                     .expect("Failed to write external frontend dependency to local file");
             }
+            */
             outfile.write_all(b"\n").unwrap();
         } else {
             writeln!(outfile, "{}", line).unwrap();
