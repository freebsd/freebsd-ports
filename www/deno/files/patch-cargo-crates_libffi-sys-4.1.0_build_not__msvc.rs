--- cargo-crates/libffi-sys-4.1.0/build/not_msvc.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/libffi-sys-4.1.0/build/not_msvc.rs
@@ -71,7 +71,8 @@ pub fn configure_libffi(prefix: PathBuf, build_dir: &P
         .arg("./configure")
         .arg("--with-pic")
         .arg("--disable-shared")
-        .arg("--disable-docs");
+        .arg("--disable-docs")
+        .arg("--disable-multi-os-directory");
 
     let target = std::env::var("TARGET").unwrap();
     let host = std::env::var("HOST").unwrap();
