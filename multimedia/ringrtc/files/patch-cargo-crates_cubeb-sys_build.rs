--- cargo-crates/cubeb-sys-0.17.0/build.rs.orig	2024-11-18 16:08:09.330015000 +0100
+++ cargo-crates/cubeb-sys-0.17.0/build.rs	2024-11-18 16:01:50.423150000 +0100
@@ -33,7 +33,6 @@ fn main() {
         return;
     }
 
-    let _ = fs::remove_dir_all(env::var("OUT_DIR").unwrap());
     t!(fs::create_dir_all(env::var("OUT_DIR").unwrap()));
 
     env::remove_var("DESTDIR");
@@ -46,7 +45,7 @@ fn main() {
     let libcubeb_path = if Path::new("libcubeb").exists() {
         "libcubeb".to_owned()
     } else {
-        env::var("OUT_DIR").unwrap() + "/libcubeb"
+        "WRKDIR/libcubeb".to_owned()
     };
 
     if !Path::new(&libcubeb_path).exists() {
