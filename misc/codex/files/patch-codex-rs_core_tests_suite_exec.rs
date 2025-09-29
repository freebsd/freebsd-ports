--- codex-rs/core/tests/suite/exec.rs.orig	2025-09-27 09:06:53 UTC
+++ codex-rs/core/tests/suite/exec.rs
@@ -104,7 +104,7 @@ async fn exit_command_not_found_is_ok() {
     }
 
     let tmp = TempDir::new().expect("should be able to create temp dir");
-    let cmd = vec!["/bin/bash", "-c", "nonexistent_command_12345"];
+    let cmd = vec!["/bin/sh", "-c", "nonexistent_command_12345"];
     run_test_cmd(tmp, cmd).await.unwrap();
 }
 
