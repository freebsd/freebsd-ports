-- Add FreeBSD-specific command_builder initialization.
-- The upstream code only handles Windows, macOS, and Linux for the
-- platform-specific command builder setup. FreeBSD is a Unix system
-- but does not match any of the existing cfg blocks, so we add a
-- dedicated block that uses sh -c like the macOS fallback path.
--
-- This patch is necessary for the port to compile on FreeBSD.
--
--- src/tools/shell.rs.orig	2026-05-31 00:16:14 UTC
+++ src/tools/shell.rs
@@ -201,6 +201,13 @@ impl Tool for ExecuteCommandTool {
             cmd
         };
 
+        #[cfg(target_os = "freebsd")]
+        let mut command_builder = {
+            let mut cmd = tokio::process::Command::new("sh");
+            cmd.arg("-c").arg(&command);
+            cmd
+        };
+
         #[cfg(target_os = "linux")]
         let mut command_builder = if sandboxed
             && let crate::sandbox::SandboxCapability::Bubblewrap { bwrap_path } =
