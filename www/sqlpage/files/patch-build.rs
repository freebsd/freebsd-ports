diff --git build.rs build.rs
index 3c2bdee..74538c9 100644
--- build.rs
+++ build.rs
@@ -1,6 +1,7 @@
 use actix_rt::spawn;
 use libflate::gzip;
 use std::collections::hash_map::DefaultHasher;
+use std::fs;
 use std::fs::File;
 use std::hash::Hasher;
 use std::io::Read;
@@ -56,13 +57,15 @@ async fn process_input_file(client: &awc::Client, path_out: &Path, original: Fil
     for l in BufReader::new(original).lines() {
         let line = l.unwrap();
         if line.starts_with("/* !include https://") {
-            let url = line
-                .trim_start_matches("/* !include ")
+            let file_path = line
+                .trim_start_matches("/* !include https://cdn.jsdelivr.net/npm/")
                 .trim_end_matches(" */");
             if std::env::var("DOCS_RS").is_err() {
-                copy_url_to_opened_file(client, url, &mut outfile).await;
+                let contents = fs::read_to_string(file_path).expect("Failed to read data from file {file_path}");
+                outfile.write_all(contents.as_bytes()).expect("Failed to write to file");
+                //    copy_url_to_opened_file(client, url, &mut outfile).await;
             } else {
-                println!("cargo:warning=Skipping download of {url} because we're building docs.");
+                println!("cargo:warning=Skipping {file_path} because we're building docs.");
                 return;
             }
             outfile.write_all(b"\n").unwrap();
@@ -102,9 +105,8 @@ async fn download_url_to_path(client: &awc::Client, url: &str, path: &Path) {
     let mut resp = client.get(url).send().await.unwrap_or_else(|err| {
         let path = make_url_path(url);
         panic!(
-            "We need to download external frontend dependencies to build the static frontend. \n\
-                Could not download static asset. You can manually download the file with: \n\
-                curl {url:?} > {path:?} \n\
+            "We need to download external frontend dependencies to build the static frontend. \
+                Could not download {url}. You can manually download the file and place it in {path:?}\
                 {err}"
         )
     });
