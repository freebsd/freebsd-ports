--- codex-rs/cli/src/main.rs.orig	2025-09-27 08:29:56 UTC
+++ codex-rs/cli/src/main.rs
@@ -219,6 +219,9 @@ fn pre_main_hardening() {
         #[cfg(target_os = "macos")]
         crate::pre_main_hardening::pre_main_hardening_macos();
 
+        #[cfg(target_os = "freebsd")]
+        crate::pre_main_hardening::pre_main_hardening_freebsd();
+
         #[cfg(windows)]
         crate::pre_main_hardening::pre_main_hardening_windows();
     }
