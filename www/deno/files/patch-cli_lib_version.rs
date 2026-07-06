libsui:find_section() operates on the binary at std::env::current_exe()
Rather than patch libsui to fix the path, set release_channel always
to Stable, since we only port stable releases.

Index: cli/lib/version.rs
--- cli/lib/version.rs.orig	2026-07-01 13:28:43 UTC
+++ cli/lib/version.rs
@@ -32,11 +32,7 @@ pub static DENO_VERSION_INFO: std::sync::LazyLock<Deno
 
 pub static DENO_VERSION_INFO: std::sync::LazyLock<DenoVersionInfo> =
   std::sync::LazyLock::new(|| {
-    #[cfg(not(all(
-      debug_assertions,
-      target_os = "macos",
-      target_arch = "x86_64"
-    )))]
+    #[cfg(not(target_os="freebsd"))]
     let release_channel = libsui::find_section("denover")
       .ok()
       .flatten()
@@ -51,6 +47,9 @@ pub static DENO_VERSION_INFO: std::sync::LazyLock<Deno
           release_channel_from_version_string(DENO_VERSION)
         }
       });
+
+    #[cfg(target_os="freebsd")]
+    let release_channel = ReleaseChannel::Stable;
 
     #[cfg(all(debug_assertions, target_os = "macos", target_arch = "x86_64"))]
     let release_channel = if IS_CANARY {
