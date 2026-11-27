--- src/mxc-sdk/src/core/mxc_engine/mod.rs.orig	2026-11-14 19:09:57 UTC
+++ src/mxc-sdk/src/core/mxc_engine/mod.rs
@@ -37,7 +37,7 @@ mod request_probe;
 mod probe;
 #[cfg(target_os = "windows")]
 mod request_probe;
-#[cfg(any(target_os = "windows", target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_os = "macos"))]
 mod run;
 mod state_aware;
 #[cfg(target_os = "windows")]
@@ -52,7 +52,7 @@ pub use run::resolve_runner_for_audit;
 pub use request_probe::{probe_execution_request, ProbeFacts, ProbeOutput, UiCapabilitySupport};
 #[cfg(target_os = "windows")]
 pub use run::resolve_runner_for_audit;
-#[cfg(any(target_os = "windows", target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_os = "macos"))]
 pub use run::{log_policy_hash, resolve_runner, run, ResolvedRunner};
 pub use state_aware::{
     exec_state_aware_attached, exec_state_aware_capture_json, exec_state_aware_json,
