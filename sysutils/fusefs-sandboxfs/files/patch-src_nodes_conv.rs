Unbreak on i386

error[E0308]: mismatched types
  --> src/nodes/conv.rs:72:19
   |
72 |     Timespec::new(val.tv_sec() as sys::time::time_t, usec)
   |                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ expected i64, found i32

--- src/nodes/conv.rs.orig	2019-02-06 10:25:59 UTC
+++ src/nodes/conv.rs
@@ -69,7 +69,7 @@ pub fn timeval_to_timespec(val: sys::time::TimeVal) ->
     } else {
         val.tv_usec() as i32
     };
-    Timespec::new(val.tv_sec() as sys::time::time_t, usec)
+    Timespec::new((val.tv_sec() as sys::time::time_t).into(), usec)
 }
 
 /// Converts a file type as returned by the file system to a FUSE file type.
