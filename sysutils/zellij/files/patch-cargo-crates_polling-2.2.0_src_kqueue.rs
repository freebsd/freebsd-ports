--- cargo-crates/polling-2.2.0/src/kqueue.rs.orig	2026-04-05 23:16:50 UTC
+++ cargo-crates/polling-2.2.0/src/kqueue.rs
@@ -85,6 +85,7 @@ impl Poller {
                 fflags: 0,
                 data: 0,
                 udata: ev.key as _,
+                ext: [0, 0, 0, 0],
             },
             libc::kevent {
                 ident: fd as _,
@@ -93,6 +94,7 @@ impl Poller {
                 fflags: 0,
                 data: 0,
                 udata: ev.key as _,
+                ext: [0, 0, 0, 0],
             },
         ];
 
@@ -203,6 +205,7 @@ impl Events {
             fflags: 0,
             data: 0,
             udata: 0 as _,
+            ext: [0, 0, 0, 0],
         };
         let list = vec![ev; 1000].into_boxed_slice();
         let len = 0;
