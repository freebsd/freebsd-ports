--- cargo-crates/deno-libffi-sys-0.0.7/build/not_msvc.rs.orig	2021-08-17 13:39:00.141977000 +0000
+++ cargo-crates/deno-libffi-sys-0.0.7/build/not_msvc.rs	2021-08-17 13:38:46.188985000 +0000
@@ -48,7 +48,8 @@ pub fn configure_libffi(prefix: PathBuf, build_dir: &P
     command
         .arg("configure")
         .arg("--with-pic")
-        .arg("--disable-docs");
+        .arg("--disable-docs")
+        .arg("--disable-multi-os-directory");
 
     let target = std::env::var("TARGET").unwrap();
     if target != std::env::var("HOST").unwrap() {
