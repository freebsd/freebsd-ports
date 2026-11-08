-- Add png::EncodingError conversion for FreeBSD.
-- The error variant was gated to Linux/macOS only.
--- cargo-crates/tray-icon-0.21.3/src/error.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tray-icon-0.21.3/src/error.rs
@@ -10,7 +10,7 @@ pub enum Error {
 pub enum Error {
     #[error(transparent)]
     OsError(#[from] std::io::Error),
-    #[cfg(any(target_os = "linux", target_os = "macos"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
     #[error(transparent)]
     PngEncodingError(#[from] png::EncodingError),
     #[error("not on the main thread")]
