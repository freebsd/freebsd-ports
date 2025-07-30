Patch the code to be compatible with the library bump.

--- src/core/engine.rs.orig	2024-01-09 13:27:28 UTC
+++ src/core/engine.rs
@@ -48,9 +48,9 @@ pub fn crack_file(
     let mut success = None;
 
     let progress_bar = ProgressBar::new(producer.size() as u64);
-    progress_bar.set_draw_delta(1000);
     progress_bar.set_style(ProgressStyle::default_bar()
-        .template("{spinner:.green} [{elapsed_precise}] [{bar:40.cyan/blue}] {pos:>7}/{len:7} {percent}% {per_sec} ETA: {eta}"));
+        .template("{spinner:.green} [{elapsed_precise}] [{bar:40.cyan/blue}] {pos:>7}/{len:7} {percent}% {per_sec} ETA: {eta}")
+        .unwrap());
 
     loop {
         match success_reader.try_recv() {
