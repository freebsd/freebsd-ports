--- codex-rs/core/tests/suite/shell_serialization.rs.orig	2025-10-25 21:16:34 UTC
+++ codex-rs/core/tests/suite/shell_serialization.rs
@@ -238,6 +238,9 @@ async fn shell_output_for_freeform_tool_records_durati
     #[cfg(target_os = "linux")]
     let sleep_cmd = vec!["/bin/bash", "-c", "sleep 1"];
 
+    #[cfg(target_os = "freebsd")]
+    let sleep_cmd = vec!["/bin/bash", "-c", "sleep 1"];
+
     #[cfg(target_os = "macos")]
     let sleep_cmd = vec!["/bin/bash", "-c", "sleep 1"];
 
