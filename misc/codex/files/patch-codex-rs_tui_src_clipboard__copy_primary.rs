--- codex-rs/tui/src/clipboard_copy/primary.rs.orig	2026-10-07 05:14:06 UTC
+++ codex-rs/tui/src/clipboard_copy/primary.rs
@@ -1,13 +1,13 @@
 //! Local X11 PRIMARY selection. Never forward PRIMARY over SSH or tmux, or
 //! accidentally target a Wayland compositor or WSL host clipboard.
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use super::ClipboardLease;
 use super::CopyOutcome;
 use std::time::Instant;
 
 pub(crate) fn available() -> bool {
-    cfg!(target_os = "linux")
+    cfg!(any(target_os = "linux", target_os = "freebsd"))
         && std::env::var_os("DISPLAY").is_some()
         && std::env::var_os("WAYLAND_DISPLAY").is_none()
         && !super::is_ssh_session()
@@ -16,7 +16,7 @@ pub(crate) fn available() -> bool {
         && crate::tui::detect_vscode_terminal() != crate::tui::VscodeDetection::VsCode
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub(super) fn copy(
     text: &str,
     begin_delivery: impl FnOnce() -> Result<(), String>,
@@ -34,7 +34,7 @@ pub(super) fn copy(
     ))))
 }
 
-#[cfg(not(target_os = "linux"))]
+#[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
 pub(super) fn copy(
     _text: &str,
     _begin_delivery: impl FnOnce() -> Result<(), String>,
@@ -42,7 +42,7 @@ pub(super) fn copy(
     Err("X11 primary selection unavailable".into())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub(super) fn read(deadline: Instant) -> Result<String, String> {
     use arboard::GetExtLinux;
     crate::clipboard_paste::text::native_result(
@@ -56,7 +56,7 @@ pub(super) fn read(deadline: Instant) -> Result<String
     )
 }
 
-#[cfg(not(target_os = "linux"))]
+#[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
 pub(super) fn read(_deadline: Instant) -> Result<String, String> {
     Err("X11 primary selection unavailable".into())
 }
