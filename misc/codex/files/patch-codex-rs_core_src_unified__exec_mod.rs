--- codex-rs/core/src/unified_exec/mod.rs.orig	2025-09-27 09:05:00 UTC
+++ codex-rs/core/src/unified_exec/mod.rs
@@ -434,7 +434,7 @@ mod tests {
         let open_shell = manager
             .handle_request(UnifiedExecRequest {
                 session_id: None,
-                input_chunks: &["bash".to_string(), "-i".to_string()],
+                input_chunks: &["sh".to_string(), "-i".to_string()],
                 timeout_ms: Some(2_500),
             })
             .await?;
@@ -473,7 +473,7 @@ mod tests {
         let shell_a = manager
             .handle_request(UnifiedExecRequest {
                 session_id: None,
-                input_chunks: &["/bin/bash".to_string(), "-i".to_string()],
+                input_chunks: &["/bin/sh".to_string(), "-i".to_string()],
                 timeout_ms: Some(2_500),
             })
             .await?;
@@ -521,7 +521,7 @@ mod tests {
         let open_shell = manager
             .handle_request(UnifiedExecRequest {
                 session_id: None,
-                input_chunks: &["bash".to_string(), "-i".to_string()],
+                input_chunks: &["sh".to_string(), "-i".to_string()],
                 timeout_ms: Some(2_500),
             })
             .await?;
@@ -616,7 +616,7 @@ mod tests {
         let open_shell = manager
             .handle_request(UnifiedExecRequest {
                 session_id: None,
-                input_chunks: &["/bin/bash".to_string(), "-i".to_string()],
+                input_chunks: &["/bin/sh".to_string(), "-i".to_string()],
                 timeout_ms: Some(2_500),
             })
             .await?;
