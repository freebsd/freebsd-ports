--- src/mxc-sdk/src/core/mxc_engine/mod.rs.orig	2026-10-29 01:47:32 UTC
+++ src/mxc-sdk/src/core/mxc_engine/mod.rs
@@ -39,7 +39,7 @@ mod request_probe;
 mod probe;
 #[cfg(target_os = "windows")]
 mod request_probe;
-#[cfg(any(target_os = "windows", target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_os = "macos"))]
 mod run;
 mod state_aware;
 #[cfg(target_os = "windows")]
@@ -58,7 +58,7 @@ pub use run::resolve_runner_for_audit;
 }
 #[cfg(target_os = "windows")]
 pub use run::resolve_runner_for_audit;
-#[cfg(any(target_os = "windows", target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_os = "macos"))]
 pub use run::{log_policy_hash, resolve_runner, run, ResolvedRunner};
 pub use state_aware::{
     exec_state_aware_attached, exec_state_aware_json, exec_state_aware_pty_json,
