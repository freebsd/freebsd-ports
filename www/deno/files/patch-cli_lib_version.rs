libsui:find_section() operates on the binary at std::env::current_exe()
Rather than patch libsui to fix the path, set release_channel always
to Stable, since we only port stable releases.

Index: cli/lib/version.rs
--- cli/lib/version.rs.orig
+++ cli/lib/version.rs
@@ -23,6 +23,7 @@ const IS_RC: bool = option_env!("DENO_RC").is_some();
 
 pub static DENO_VERSION_INFO: std::sync::LazyLock<DenoVersionInfo> =
   std::sync::LazyLock::new(|| {
+    #[cfg(not(target_os="openbsd"))]
     let release_channel = libsui::find_section("denover")
       .and_then(|buf| std::str::from_utf8(buf).ok())
       .and_then(|str_| ReleaseChannel::deserialize(str_).ok())
@@ -35,6 +36,9 @@ pub static DENO_VERSION_INFO: std::sync::LazyLock<Deno
           ReleaseChannel::Stable
         }
       });
+
+    #[cfg(target_os="openbsd")]
+    let release_channel = ReleaseChannel::Stable;
 
     DenoVersionInfo {
       deno: if release_channel == ReleaseChannel::Canary {
