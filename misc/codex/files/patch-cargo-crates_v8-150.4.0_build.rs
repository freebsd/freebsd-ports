--- cargo-crates/v8-150.4.0/build.rs.orig	2026-08-22 00:08:58 UTC
+++ cargo-crates/v8-150.4.0/build.rs
@@ -289,8 +289,6 @@ fn build_v8(is_asan: bool) {
     download_ninja_gn_binaries();
   }
 
-  download_rust_toolchain();
-
   // `#[cfg(...)]` attributes don't work as expected from build.rs -- they refer to the configuration
   // of the host system which the build.rs script will be running on. In short, `cfg!(target_<os/arch>)`
   // is actually the host os/arch instead of target os/arch while cross compiling. Instead, Environment variables
@@ -420,8 +418,10 @@ fn build_v8(is_asan: bool) {
     gn_args.push(r#"target_cpu="arm""#.to_string());
     gn_args.push(r#"v8_target_cpu="arm""#.to_string());
     gn_args.push("use_sysroot=true".to_string());
-    maybe_install_sysroot("i386");
-    maybe_install_sysroot("arm");
+    if target_os == "linux" {
+      maybe_install_sysroot("i386");
+      maybe_install_sysroot("arm");
+    }
   }
   if target_arch == "riscv64" {
     gn_args.push(r#"target_cpu="riscv64""#.to_string());
@@ -504,7 +504,9 @@ fn build_v8(is_asan: bool) {
     gn_args.push(format!(r#"target_cpu="{arch}""#).to_string());
     gn_args.push(r#"target_os="android""#.to_string());
     gn_args.push("treat_warnings_as_errors=false".to_string());
-    gn_args.push("use_sysroot=true".to_string());
+    if target_os == "linux" {
+      gn_args.push("use_sysroot=true".to_string());
+    }
 
     // NDK 23 and above removes libgcc entirely.
     // https://github.com/rust-lang/rust/pull/85806
