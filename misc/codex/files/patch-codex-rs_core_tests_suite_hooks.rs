--- codex-rs/core/tests/suite/hooks.rs.orig	1970-01-01 00:00:00 UTC
+++ codex-rs/core/tests/suite/hooks.rs
@@ -3111,7 +3111,7 @@ async fn permission_request_hook_allow_bypasses_strict
     let command_call_id = "strict-hook-exec-command";
     let marker_name = "strict-hook-exec-command-marker";
     let command = match test_target_os() {
-        TestTargetOs::Linux | TestTargetOs::MacOs => format!("rm -f {marker_name}"),
+        TestTargetOs::Linux | TestTargetOs::MacOs | TestTargetOs::FreeBsd => format!("rm -f {marker_name}"),
         TestTargetOs::Windows => {
             format!("Remove-Item -Force -ErrorAction SilentlyContinue {marker_name}")
         }
