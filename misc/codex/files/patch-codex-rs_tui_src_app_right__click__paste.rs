--- codex-rs/tui/src/app/right_click_paste.rs.orig	2026-10-15 18:57:07 UTC
+++ codex-rs/tui/src/app/right_click_paste.rs
@@ -32,7 +32,7 @@ impl PasteEnvironment {
     pub(crate) fn detect() -> Self {
         Self {
             primary: crate::clipboard_copy::primary::available(),
-            platform_default: cfg!(any(target_os = "windows", target_os = "linux")),
+            platform_default: cfg!(any(target_os = "windows", target_os = "linux", target_os = "freebsd")),
             ssh: crate::clipboard_copy::is_ssh_session(),
             wsl: crate::clipboard_copy::is_wsl_session(),
             vscode: tui::detect_vscode_terminal(),
