--- cargo-crates/v8-150.4.0/build.rs.orig	2026-08-22 00:08:58 UTC
+++ cargo-crates/v8-150.4.0/build.rs
@@ -288,8 +288,6 @@
   if need_gn_ninja_download() {
     download_ninja_gn_binaries();
   }
-
-  download_rust_toolchain();
 
   // `#[cfg(...)]` attributes don't work as expected from build.rs -- they refer to the configuration
   // of the host system which the build.rs script will be running on. In short, `cfg!(target_<os/arch>)`
@@ -313,7 +311,11 @@
   ));
 
   let extra_args = {
-    if env::var("CARGO_FEATURE_V8_ENABLE_SANDBOX").is_ok() {
+    // The PPC64 backend does not support the sandbox (Liftoff and the macro
+    // assembler static_assert on it), so build without it there.
+    if env::var("CARGO_FEATURE_V8_ENABLE_SANDBOX").is_ok()
+      && target_arch != "powerpc64"
+    {
       vec![
         // Enable pointer compression (along with its dependencies)
         "v8_enable_sandbox=true",
@@ -420,8 +422,10 @@
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
@@ -433,6 +437,12 @@
       maybe_install_sysroot("amd64");
     }
   }
+  if target_arch == "powerpc64" {
+    // The PPC64 Maglev backend is incomplete (the shared Maglev code still
+    // expects sandbox support from it); Node.js does not build Maglev on
+    // PPC64 either.
+    gn_args.push("v8_enable_maglev=false".to_string());
+  }
 
   // musl libc. V8's build targets glibc by default; the vendored build config
   // grows a target-scoped `use_musl` arg (see //build/config/rust.gni,
@@ -504,7 +514,9 @@
     gn_args.push(format!(r#"target_cpu="{arch}""#).to_string());
     gn_args.push(r#"target_os="android""#.to_string());
     gn_args.push("treat_warnings_as_errors=false".to_string());
-    gn_args.push("use_sysroot=true".to_string());
+    if target_os == "linux" {
+      gn_args.push("use_sysroot=true".to_string());
+    }
 
     // NDK 23 and above removes libgcc entirely.
     // https://github.com/rust-lang/rust/pull/85806
