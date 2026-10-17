--- codex-rs/tui/src/clipboard_copy/worker.rs.orig	2026-10-15 18:57:07 UTC
+++ codex-rs/tui/src/clipboard_copy/worker.rs
@@ -433,8 +433,8 @@ impl ClipboardWorker {
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
