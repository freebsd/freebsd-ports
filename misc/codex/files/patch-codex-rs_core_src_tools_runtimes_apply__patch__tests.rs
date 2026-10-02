--- codex-rs/core/src/tools/runtimes/apply_patch_tests.rs.orig	2026-09-18 19:04:49 UTC
+++ codex-rs/core/src/tools/runtimes/apply_patch_tests.rs
@@ -47,6 +47,15 @@ fn test_turn_environment(environment_id: &str) -> crat
     )
 }
 
+#[cfg(any(target_os = "freebsd", target_os = "openbsd"))]
+#[tokio::test]
+async fn local_bsd_omits_unenforceable_apply_patch_sandbox() {
+    let environment = test_turn_environment(codex_exec_server::LOCAL_ENVIRONMENT_ID);
+    let sandbox = environment.sandbox_context(/*additional_permissions*/ None);
+
+    assert!(apply_patch_file_system_sandbox(&environment, Some(&sandbox)).is_none());
+}
+
 #[test]
 fn wants_no_sandbox_approval_granular_respects_sandbox_flag() {
     let runtime = ApplyPatchRuntime::new();
