--- build.rs.orig
+++ build.rs
@@ -1,6 +1,7 @@
 use actix_rt::spawn;
 use libflate::gzip;
 use std::collections::hash_map::DefaultHasher;
+use std::fs;
 use std::fs::File;
 use std::hash::Hasher;
 use std::io::Read;
@@ -55,10 +56,12 @@ async fn process_input_file(client: &awc::Client, path_out: &Path, original: Fil
     for l in BufReader::new(original).lines() {
         let line = l.unwrap();
         if line.starts_with("/* !include https://") {
-            let url = line
-                .trim_start_matches("/* !include ")
+            let file_path = line
+                .trim_start_matches("/* !include https://cdn.jsdelivr.net/npm/")
                 .trim_end_matches(" */");
-            copy_url_to_opened_file(client, url, &mut outfile).await;
+            let contents = fs::read_to_string(file_path).expect("Failed to read data from file {file_path}");
+            outfile.write_all(contents.as_bytes()).expect("Failed to write to file");
+            //    copy_url_to_opened_file(client, url, &mut outfile).await;
             outfile.write_all(b"\n").unwrap();
         } else {
             writeln!(outfile, "{}", line).unwrap();
