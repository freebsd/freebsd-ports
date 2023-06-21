--- cargo-crates/libffi-sys-2.2.1/build/not_msvc.rs.orig	2022-03-07 08:06:36 UTC
+++ cargo-crates/libffi-sys-2.2.1/build/not_msvc.rs
@@ -50,7 +50,8 @@ pub fn configure_libffi(prefix: PathBuf, build_dir: &P
         .arg("configure")
         .arg("--with-pic")
         .arg("--disable-shared")
-        .arg("--disable-docs");
+        .arg("--disable-docs")
+        .arg("--disable-multi-os-directory");
 
     let target = std::env::var("TARGET").unwrap();
     let host = std::env::var("HOST").unwrap();
