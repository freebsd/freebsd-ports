--- cargo-crates/v8-0.68.0/build.rs.orig	2020-07-22 09:53:02 UTC
+++ cargo-crates/v8-0.68.0/build.rs
@@ -255,6 +255,8 @@ fn platform() -> String {
   let os = "mac";
   #[cfg(target_os = "windows")]
   let os = "windows";
+  #[cfg(target_os = "freebsd")]
+  let os = "freebsd";
 
   #[cfg(target_arch = "x86_64")]
   let arch = "amd64";
