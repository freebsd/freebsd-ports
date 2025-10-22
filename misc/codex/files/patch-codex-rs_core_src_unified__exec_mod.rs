--- codex-rs/core/src/unified_exec/mod.rs.orig	2025-10-17 16:46:07 UTC
+++ codex-rs/core/src/unified_exec/mod.rs
@@ -445,7 +445,7 @@ mod tests {
         let open_shell = manager
             .handle_request(UnifiedExecRequest {
                 session_id: None,
-                input_chunks: &["bash".to_string(), "-i".to_string()],
+                input_chunks: &["sh".to_string(), "-i".to_string()],
                 timeout_ms: Some(2_500),
             })
             .await?;
@@ -484,7 +484,7 @@ mod tests {
         let shell_a = manager
             .handle_request(UnifiedExecRequest {
                 session_id: None,
-                input_chunks: &["/bin/bash".to_string(), "-i".to_string()],
+                input_chunks: &["/bin/sh".to_string(), "-i".to_string()],
                 timeout_ms: Some(2_500),
             })
             .await?;
@@ -532,7 +532,7 @@ mod tests {
         let open_shell = manager
             .handle_request(UnifiedExecRequest {
                 session_id: None,
-                input_chunks: &["bash".to_string(), "-i".to_string()],
+                input_chunks: &["sh".to_string(), "-i".to_string()],
                 timeout_ms: Some(2_500),
             })
             .await?;
@@ -627,7 +627,7 @@ mod tests {
         let open_shell = manager
             .handle_request(UnifiedExecRequest {
                 session_id: None,
-                input_chunks: &["/bin/bash".to_string(), "-i".to_string()],
+                input_chunks: &["/bin/sh".to_string(), "-i".to_string()],
                 timeout_ms: Some(2_500),
             })
             .await?;
