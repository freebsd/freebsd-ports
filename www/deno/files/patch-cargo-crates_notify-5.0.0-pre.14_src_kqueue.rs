From 41a74f0e98a1af386749ad3be4a197865054f17f Mon Sep 17 00:00:00 2001
From: Greg V <greg@unrelenting.technology>
Date: Fri, 15 Apr 2022 02:20:44 +0300
Subject: [PATCH] kqueue: fix build on FreeBSD

The kqueue crate supports platform-specific events, so the build was failing on FreeBSD with:
error[E0004]: non-exhaustive patterns: `Open`, `CloseWrite` and `Close` not covered
---
 src/kqueue.rs | 4 ++++
 1 file changed, 4 insertions(+)

diff --git a/src/kqueue.rs b/src/kqueue.rs
index 51a1990..30d3d2a 100644
--- cargo-crates/notify-5.0.0-pre.14/src/kqueue.rs
+++ cargo-crates/notify-5.0.0-pre.14/src/kqueue.rs
@@ -263,6 +263,10 @@ impl EventLoop {
                             remove_watches.push(path.clone());
                             Ok(Event::new(EventKind::Remove(RemoveKind::Any)).add_path(path))
                         }
+
+                        // On different BSD variants, different extra events may be present
+                        #[allow(unreachable_patterns)]
+                        _ => Ok(Event::new(EventKind::Other)),
                     };
                     self.event_handler.handle_event(event);
                 }
