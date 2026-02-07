libsui:find_section() operates on the binary at std::env::current_exe()
Rather than patch libsui to fix the path, set release_channel always
to Stable, since we only port stable releases.

Index: cli/lib/version.rs
--- cli/lib/version.rs.orig
+++ cli/lib/version.rs
@@ -23,11 +23,7 @@ const IS_RC: bool = option_env!("DENO_RC").is_some();
 
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
@@ -42,6 +38,9 @@ pub static DENO_VERSION_INFO: std::sync::LazyLock<Deno
           ReleaseChannel::Stable
         }
       });
+
+    #[cfg(target_os="freebsd")]
+    let release_channel = ReleaseChannel::Stable;
 
     #[cfg(all(debug_assertions, target_os = "macos", target_arch = "x86_64"))]
     let release_channel = if IS_CANARY {
