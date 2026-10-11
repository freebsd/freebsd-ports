--- tgrep-core/src/managed/process.rs.orig	2026-10-11 22:42:51 UTC
+++ tgrep-core/src/managed/process.rs
@@ -362,7 +362,7 @@ impl OwnedChild {
             if unsafe {
                 libc::waitid(
                     libc::P_PID,
-                    child.id(),
+                    child.id().into(),
                     &mut info,
                     libc::WEXITED | libc::WNOHANG | libc::WNOWAIT,
                 )
