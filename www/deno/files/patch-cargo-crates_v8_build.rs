--- cargo-crates/v8-0.73.0/build.rs.orig	2020-07-22 09:53:02 UTC
+++ cargo-crates/v8-0.73.0/build.rs
@@ -266,10 +266,13 @@ fn platform() -> String {
   let os = "mac";
   #[cfg(target_os = "windows")]
   let os = "windows";
+  #[cfg(target_os = "freebsd")]
+  let os = "freebsd";
   #[cfg(not(any(
     target_os = "linux",
     target_os = "macos",
-    target_os = "windows"
+    target_os = "windows",
+    target_os = "freebsd"
   )))]
   let arch = "unknown";
 
