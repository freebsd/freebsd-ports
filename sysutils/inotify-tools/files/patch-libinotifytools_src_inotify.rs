-- Fix error handling in remove_inotify_watch() on systems where inotify_rm_watch()
-- is provided by a user-space library (e.g. FreeBSD's libinotify).
-- The wrapper returned -1 on failure but stored the return value itself as the
-- error code instead of reading errno, so inotifytools_error() reported
-- "Unknown error: -1" and unit tests failed.
-- Reference: upstream issue https://github.com/inotify-tools/inotify-tools/issues/108

--- libinotifytools/src/inotify.rs.orig	2026-10-07 03:12:00 UTC
+++ libinotifytools/src/inotify.rs
@@ -531,9 +531,10 @@ impl InotifyState {
         }
         let status = unsafe { sys::inotify_rm_watch(self.fd, w.wd) };
         if status < 0 {
-            ceprint!("Failed to remove watch on ", w.filename, ": ", strerror(status), "\n");
-            self.error = status;
+            let err = errno();
+            ceprint!("Failed to remove watch on ", w.filename, ": ", strerror(err), "\n");
+            self.error = err;
             return false;
         }
         true
