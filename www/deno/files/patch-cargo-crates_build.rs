--- cargo-crates/v8-142.2.0/build.rs.orig	2006-07-24 03:21:28 UTC
+++ cargo-crates/v8-142.2.0/build.rs
@@ -251,7 +251,7 @@ fn build_v8(is_asan: bool) {
     download_ninja_gn_binaries();
   }
 
-  download_rust_toolchain();
+  //download_rust_toolchain();
 
   // `#[cfg(...)]` attributes don't work as expected from build.rs -- they refer to the configuration
   // of the host system which the build.rs script will be running on. In short, `cfg!(target_<os/arch>)`
@@ -324,16 +324,10 @@ fn build_v8(is_asan: bool) {
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
@@ -353,7 +347,6 @@ fn build_v8(is_asan: bool) {
     gn_args.push(format!(r#"target_cpu="{arch}""#).to_string());
     gn_args.push(r#"target_os="android""#.to_string());
     gn_args.push("treat_warnings_as_errors=false".to_string());
-    gn_args.push("use_sysroot=true".to_string());
 
     // NDK 23 and above removes libgcc entirely.
     // https://github.com/rust-lang/rust/pull/85806
