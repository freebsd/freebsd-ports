--- codex-rs/core/tests/suite/shell_serialization.rs.orig	2025-11-04 20:00:53 UTC
+++ codex-rs/core/tests/suite/shell_serialization.rs
@@ -398,6 +398,9 @@ async fn shell_output_for_freeform_tool_records_durati
     #[cfg(target_os = "linux")]
     let sleep_cmd = vec!["/bin/bash", "-c", "sleep 1"];
 
+    #[cfg(target_os = "freebsd")]
+    let sleep_cmd = vec!["/bin/bash", "-c", "sleep 1"];
+
     #[cfg(target_os = "macos")]
     let sleep_cmd = vec!["/bin/bash", "-c", "sleep 1"];
 
