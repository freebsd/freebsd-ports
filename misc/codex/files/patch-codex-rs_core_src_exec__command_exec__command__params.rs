--- codex-rs/core/src/exec_command/exec_command_params.rs.orig	2025-09-27 09:00:51 UTC
+++ codex-rs/core/src/exec_command/exec_command_params.rs
@@ -33,7 +33,7 @@ fn default_shell() -> String {
 }
 
 fn default_shell() -> String {
-    "/bin/bash".to_string()
+    "/bin/sh".to_string()
 }
 
 #[derive(Debug, Deserialize, Serialize)]
