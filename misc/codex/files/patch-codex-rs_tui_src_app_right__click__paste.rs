--- codex-rs/tui/src/app/right_click_paste.rs.orig	2026-10-07 05:10:14 UTC
+++ codex-rs/tui/src/app/right_click_paste.rs
@@ -29,7 +29,7 @@ impl PasteEnvironment {
     pub(super) fn detect() -> Self {
         Self {
             primary: crate::clipboard_copy::primary::available(),
-            platform_default: cfg!(any(target_os = "windows", target_os = "linux")),
+            platform_default: cfg!(any(target_os = "windows", target_os = "linux", target_os = "freebsd")),
             ssh: crate::clipboard_copy::is_ssh_session(),
             wsl: crate::clipboard_copy::is_wsl_session(),
             vscode: tui::detect_vscode_terminal(),
