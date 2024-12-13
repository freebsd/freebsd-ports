--- cargo-crates/v8-130.0.1/build.rs.orig	2006-07-24 03:21:28 UTC
+++ cargo-crates/v8-130.0.1/build.rs
@@ -238,12 +238,6 @@ fn build_v8(is_asan: bool) {
     }
   }
   // cross-compilation setup
-  if target_arch == "aarch64" {
-    gn_args.push(r#"target_cpu="arm64""#.to_string());
-    gn_args.push("use_sysroot=true".to_string());
-    maybe_install_sysroot("arm64");
-    maybe_install_sysroot("amd64");
-  }
   if target_arch == "arm" {
     gn_args.push(r#"target_cpu="arm""#.to_string());
     gn_args.push(r#"v8_target_cpu="arm""#.to_string());
