--- cargo-crates/cpal-0.18.1/src/host/mod.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/cpal-0.18.1/src/host/mod.rs
@@ -225,6 +225,7 @@ pub(crate) use error_emit::try_emit_error;
 
 /// Convert a frame count at a given sample rate to a [`std::time::Duration`].
 #[cfg(any(
+    target_os = "freebsd",
     target_os = "linux",
     target_os = "windows",
     target_vendor = "apple",
