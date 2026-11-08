--- codex-rs/core/tests/suite/remote_env.rs.orig	2026-10-27 18:19:19 UTC
+++ codex-rs/core/tests/suite/remote_env.rs
@@ -394,7 +394,7 @@ async fn remote_test_env_exposes_target_shell_and_exec
     // TODO(anp): Assert Wine-exec exposes a `C:\\...` cwd after model-visible paths preserve
     // target-native spelling instead of the Linux orchestrator's `/C:/...` representation.
     let expected_shell = match test_target_os() {
-        TestTargetOs::Linux => "<shell>bash</shell>",
+        TestTargetOs::Linux | TestTargetOs::FreeBsd => "<shell>bash</shell>",
         TestTargetOs::Windows => "<shell>powershell</shell>",
         TestTargetOs::MacOs => unreachable!("remote test targets do not run macOS"),
     };
@@ -416,7 +416,7 @@ async fn approved_remote_shell_runs_in_remote_cwd() ->
     skip_if_no_remote_env!(Ok(()));
 
     let (shell, command) = match test_target_os() {
-        TestTargetOs::Linux => (
+        TestTargetOs::Linux | TestTargetOs::FreeBsd => (
             "bash",
             r#"case "$PWD" in /tmp/codex-core-test-cwd-*) ;; *) echo "unexpected cwd: $PWD" >&2; exit 1 ;; esac"#,
         ),
@@ -537,7 +537,7 @@ async fn environment_permissions_follow_configuration_
     );
 
     let (shell, command) = match test_target_os() {
-        TestTargetOs::Linux => (
+        TestTargetOs::Linux | TestTargetOs::FreeBsd => (
             "bash",
             format!(
                 "if printf blocked > {FILE_NAME}; then echo WRITE_SUCCEEDED; else echo WRITE_DENIED; fi"
