--- codex-rs/core/src/exec_command/session_manager.rs.orig	2025-09-27 09:02:31 UTC
+++ codex-rs/core/src/exec_command/session_manager.rs
@@ -376,7 +376,7 @@ PY"#
             cmd,
             yield_time_ms: 3_000,
             max_output_tokens: 1_000, // large enough to avoid truncation here
-            shell: "/bin/bash".to_string(),
+            shell: "/bin/sh".to_string(),
             login: false,
         };
         let initial_output = match session_manager
