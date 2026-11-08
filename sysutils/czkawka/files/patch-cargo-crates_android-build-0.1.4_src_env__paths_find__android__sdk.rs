--- cargo-crates/android-build-0.1.4/src/env_paths/find_android_sdk.rs.orig	2026-09-18 03:18:38 UTC
+++ cargo-crates/android-build-0.1.4/src/env_paths/find_android_sdk.rs
@@ -74,3 +74,13 @@ pub fn windows_home_dir() -> Option<PathBuf> {
     }
     
 }
+
+#[cfg(not(any(
+    target_os = "macos",
+    target_os = "linux",
+    target_os = "windows",
+    target_os = "android"
+)))]
+pub fn find_android_sdk() -> Option<PathBuf> {
+    None
+}
