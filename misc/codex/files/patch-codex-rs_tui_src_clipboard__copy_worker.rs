--- codex-rs/tui/src/clipboard_copy/worker.rs.orig	2026-11-05 23:31:17 UTC
+++ codex-rs/tui/src/clipboard_copy/worker.rs
@@ -438,8 +438,8 @@ impl ClipboardWorker {
                     }
                     frames.schedule_frame();
                 }
-                // Finish Linux clipboard-manager handoff before disconnecting the response channel.
-                #[cfg(target_os = "linux")]
+                // Finish X11 clipboard-manager handoff before disconnecting the response channel.
+                #[cfg(any(target_os = "linux", target_os = "freebsd"))]
                 drop((lease, primary_lease));
                 drop(outgoing);
             })
