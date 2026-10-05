-- Treat FreeBSD as a Linux-like platform for auto-launch.
-- The auto-launch crate only supported Linux/macOS/Windows.
--- cargo-crates/auto-launch-0.5.0/src/lib.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/auto-launch-0.5.0/src/lib.rs
@@ -132,7 +132,7 @@ pub type Result<T> = std::result::Result<T, Error>;
 
 pub type Result<T> = std::result::Result<T, Error>;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 mod linux;
 #[cfg(target_os = "macos")]
 mod macos;
@@ -209,6 +209,7 @@ impl AutoLaunch {
     pub fn is_support() -> bool {
         cfg!(any(
             target_os = "linux",
+            target_os = "freebsd",
             target_os = "macos",
             target_os = "windows",
         ))
@@ -314,7 +315,7 @@ impl AutoLaunchBuilder {
         let app_path = self.app_path.as_ref().ok_or(Error::AppPathNotSpecified)?;
         let args = self.args.clone().unwrap_or_default();
 
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         return Ok(AutoLaunch::new(&app_name, &app_path, &args));
         #[cfg(target_os = "macos")]
         return Ok(AutoLaunch::new(
@@ -326,7 +327,7 @@ impl AutoLaunchBuilder {
         #[cfg(target_os = "windows")]
         return Ok(AutoLaunch::new(&app_name, &app_path, &args));
 
-        #[cfg(not(any(target_os = "macos", target_os = "windows", target_os = "linux")))]
+        #[cfg(not(any(target_os = "macos", target_os = "windows", target_os = "linux", target_os = "freebsd")))]
         return Err(Error::UnsupportedOS);
     }
 }
