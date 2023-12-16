--- cargo-crates/v8-0.82.0/build.rs.orig	2020-07-22 09:53:02 UTC
+++ cargo-crates/v8-0.82.0/build.rs
@@ -268,6 +268,8 @@ fn platform() -> String {
     "mac"
   } else if cfg!(target_os = "windows") {
     "windows"
+  } else if cfg!(target_os = "freebsd") {
+    "freebsd"
   } else {
     "unknown"
   };
