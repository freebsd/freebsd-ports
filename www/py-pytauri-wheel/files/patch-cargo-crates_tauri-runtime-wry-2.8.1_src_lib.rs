-- Implement WindowBuilder::skip_taskbar for FreeBSD.
-- The implementation was Linux-only, leaving the trait unimplemented on FreeBSD.
--- cargo-crates/tauri-runtime-wry-2.8.1/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tauri-runtime-wry-2.8.1/src/lib.rs
@@ -35,7 +35,7 @@ use tao::platform::macos::{EventLoopWindowTargetExtMac
 use objc2::rc::Retained;
 #[cfg(target_os = "macos")]
 use tao::platform::macos::{EventLoopWindowTargetExtMacOS, WindowBuilderExtMacOS};
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use tao::platform::unix::{WindowBuilderExtUnix, WindowExtUnix};
 #[cfg(windows)]
 use tao::platform::windows::{WindowBuilderExtWindows, WindowExtWindows};
@@ -1190,7 +1190,7 @@ impl WindowBuilder for WindowBuilderWrapper {
     self
   }
 
-  #[cfg(any(windows, target_os = "linux"))]
+  #[cfg(any(windows, target_os = "linux", target_os = "freebsd"))]
   fn skip_taskbar(mut self, skip: bool) -> Self {
     self.inner = self.inner.with_skip_taskbar(skip);
     self
