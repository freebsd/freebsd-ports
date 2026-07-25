--- cargo-crates/aube-1.32.0/src/commands/global.rs.orig	2026-07-25 06:08:48 UTC
+++ cargo-crates/aube-1.32.0/src/commands/global.rs
@@ -94,7 +94,7 @@ pub fn prefix_dir() -> miette::Result<PathBuf> {
     resolve_home()
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 fn platform_default() -> miette::Result<PathBuf> {
     if let Some(xdg) = aube_util::env::xdg_data_home() {
         return Ok(xdg.join("pnpm"));
