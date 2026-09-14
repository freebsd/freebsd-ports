--- codex-rs/core/tests/suite/workspace_roots.rs.orig	2026-09-13 22:36:38 UTC
+++ codex-rs/core/tests/suite/workspace_roots.rs
@@ -74,7 +74,7 @@ fn command_arguments(path: &str, contents: &str) -> Re
 
 fn command_arguments(path: &str, contents: &str) -> Result<String> {
     let (shell, command) = match test_target_os() {
-        TestTargetOs::Linux | TestTargetOs::MacOs => {
+        TestTargetOs::Linux | TestTargetOs::MacOs | TestTargetOs::FreeBsd => {
             ("bash", format!("printf %s '{contents}' > '{path}'"))
         }
         TestTargetOs::Windows => ("cmd", format!("echo {contents}>{path}")),
