--- cargo-crates/v8-137.2.1/build.rs.orig	2006-07-24 03:21:28 UTC
+++ cargo-crates/v8-137.2.1/build.rs
@@ -254,16 +254,10 @@ fn build_v8(is_asan: bool) {
   // cross-compilation setup
   if target_arch == "aarch64" {
     gn_args.push(r#"target_cpu="arm64""#.to_string());
-    gn_args.push("use_sysroot=true".to_string());
-    maybe_install_sysroot("arm64");
-    maybe_install_sysroot("amd64");
   }
   if target_arch == "arm" {
     gn_args.push(r#"target_cpu="arm""#.to_string());
     gn_args.push(r#"v8_target_cpu="arm""#.to_string());
-    gn_args.push("use_sysroot=true".to_string());
-    maybe_install_sysroot("i386");
-    maybe_install_sysroot("arm");
   }
 
   let target_triple = env::var("TARGET").unwrap();
@@ -283,7 +277,6 @@ fn build_v8(is_asan: bool) {
     gn_args.push(format!(r#"target_cpu="{arch}""#).to_string());
     gn_args.push(r#"target_os="android""#.to_string());
     gn_args.push("treat_warnings_as_errors=false".to_string());
-    gn_args.push("use_sysroot=true".to_string());
 
     // NDK 23 and above removes libgcc entirely.
     // https://github.com/rust-lang/rust/pull/85806
