--- codex-rs/core/src/exec_command/responses_api.rs.orig	2025-09-27 09:01:29 UTC
+++ codex-rs/core/src/exec_command/responses_api.rs
@@ -29,7 +29,7 @@ pub fn create_exec_command_tool_for_responses_api() ->
     properties.insert(
         "shell".to_string(),
         JsonSchema::String {
-            description: Some("The shell to use. Defaults to \"/bin/bash\".".to_string()),
+            description: Some("The shell to use. Defaults to \"/bin/sh\".".to_string()),
         },
     );
     properties.insert(
