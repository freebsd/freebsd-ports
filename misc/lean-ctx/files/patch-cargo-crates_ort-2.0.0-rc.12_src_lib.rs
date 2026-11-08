-- Add FreeBSD to the list of platforms where ONNX Runtime is loaded as
-- libonnxruntime.so, so the match on ORT_DYLIB_PATH is exhaustive on FreeBSD.
-- Without this arm the build fails with "non-exhaustive patterns: `Err(_)` not
-- covered" because none of the existing cfg-guarded fallback arms apply.
--
-- Upstream: already present in the current revision of https://github.com/pykeio/ort

--- cargo-crates/ort-2.0.0-rc.12/src/lib.rs.orig	2026-09-21 20:19:43 UTC
+++ cargo-crates/ort-2.0.0-rc.12/src/lib.rs
@@ -189,7 +189,7 @@ fn setup_api() -> ApiPointer {
 				Ok(s) if !s.is_empty() => s,
 				#[cfg(target_os = "windows")]
 				_ => "onnxruntime.dll".to_owned(),
-				#[cfg(any(target_os = "linux", target_os = "android"))]
+				#[cfg(any(target_os = "linux", target_os = "android", target_os = "freebsd"))]
 				_ => "libonnxruntime.so".to_owned(),
 				#[cfg(any(target_os = "macos", target_os = "ios"))]
 				_ => "libonnxruntime.dylib".to_owned()
