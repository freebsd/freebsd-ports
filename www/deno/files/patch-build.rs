--- cargo-crates/v8-0.105.0/build.rs.orig	2020-07-22 09:53:02 UTC
+++ cargo-crates/v8-0.105.0/build.rs
@@ -199,10 +199,10 @@ fn build_v8(is_asan: bool) {
   }
   // cross-compilation setup
   if target_arch == "aarch64" {
-    gn_args.push(r#"target_cpu="arm64""#.to_string());
-    gn_args.push("use_sysroot=true".to_string());
-    maybe_install_sysroot("arm64");
-    maybe_install_sysroot("amd64");
+    // gn_args.push(r#"target_cpu="arm64""#.to_string());
+    gn_args.push("use_sysroot=false".to_string());
+    // maybe_install_sysroot("arm64");
+    // maybe_install_sysroot("amd64");
   }
   if target_arch == "arm" {
     gn_args.push(r#"target_cpu="arm""#.to_string());
@@ -326,6 +326,8 @@ fn host_platform() -> String {
     "mac"
   } else if cfg!(target_os = "windows") {
     "windows"
+  } else if cfg!(target_os = "freebsd") {
+    "freebsd"
   } else {
     "unknown"
   };
