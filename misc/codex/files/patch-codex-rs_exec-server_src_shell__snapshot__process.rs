--- codex-rs/exec-server/src/shell_snapshot_process.rs.orig	2026-10-09 19:40:23 UTC
+++ codex-rs/exec-server/src/shell_snapshot_process.rs
@@ -51,7 +51,7 @@ impl SnapshotCapture {
                 if unsafe {
                     libc::waitid(
                         libc::P_PID,
-                        pid,
+                        pid.into(),
                         info.as_mut_ptr(),
                         libc::WEXITED | libc::WNOHANG | libc::WNOWAIT,
                     )
