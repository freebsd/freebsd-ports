--- cargo-crates/v8-0.40.2/build.rs.orig	2020-07-22 09:53:02 UTC
+++ cargo-crates/v8-0.40.2/build.rs
@@ -130,6 +132,10 @@ fn platform() -> &'static str {
   #[cfg(target_os = "macos")]
   {
     "mac"
+  }
+  #[cfg(target_os = "freebsd")]
+  {
+    "freebsd"
   }
 }
 
