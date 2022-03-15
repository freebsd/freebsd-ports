--- cargo-crates/libffi-sys-1.3.0/build/not_msvc.rs.orig	2022-03-07 08:06:36 UTC
+++ cargo-crates/libffi-sys-1.3.0/build/not_msvc.rs
@@ -49,7 +49,8 @@ pub fn configure_libffi(prefix: PathBuf, build_dir: &P
     command
         .arg("configure")
         .arg("--with-pic")
-        .arg("--disable-docs");
+        .arg("--disable-docs")
+	.arg("--disable-multi-os-directory");
 
     let target = std::env::var("TARGET").unwrap();
     if target != std::env::var("HOST").unwrap() {
