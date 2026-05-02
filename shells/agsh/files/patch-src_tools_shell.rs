--- src/tools/shell.rs.orig	2026-05-01 06:02:01 UTC
+++ src/tools/shell.rs
@@ -157,6 +157,13 @@ impl Tool for ExecuteCommandTool {
             cmd
         };
 
+        #[cfg(target_os = "freebsd")]
+        let mut command_builder = {
+            let mut cmd = tokio::process::Command::new("sh");
+            cmd.arg("-c").arg(&command);
+            cmd
+        };
+
         // Unix: place the child in its own session/process group via
         // `setsid` so timeouts and cancellation can kill the whole tree
         // (including backgrounded grandchildren such as `(sleep 3600 &)`)
