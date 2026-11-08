--- codex-rs/core/tests/suite/workspace_roots.rs.orig	2026-10-05 17:16:58 UTC
+++ codex-rs/core/tests/suite/workspace_roots.rs
@@ -75,7 +75,7 @@ fn command_arguments(path: &str, contents: &str) -> Re
 
 fn command_arguments(path: &str, contents: &str) -> Result<String> {
     let (shell, command) = match test_target_os() {
-        TestTargetOs::Linux | TestTargetOs::MacOs => {
+        TestTargetOs::Linux | TestTargetOs::MacOs | TestTargetOs::FreeBsd => {
             ("bash", format!("printf %s '{contents}' > '{path}'"))
         }
         TestTargetOs::Windows => ("cmd", format!("echo {contents}>{path}")),
