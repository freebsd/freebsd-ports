Unbreak on i386

error[E0308]: mismatched types
  --> src/nodes/conv.rs:72:19
   |
72 |     Timespec::new(val.tv_sec() as sys::time::time_t, usec)
   |                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ expected i64, found i32

--- src/nodes/conv.rs.orig	2019-10-24 19:42:29 UTC
+++ src/nodes/conv.rs
@@ -69,7 +69,7 @@ pub fn timeval_to_timespec(val: sys::time::TimeVal) ->
     } else {
         val.tv_usec() as i32
     };
-    Timespec::new(val.tv_sec() as sys::time::time_t, usec)
+    Timespec::new((val.tv_sec() as sys::time::time_t).into(), usec)
 }
 
 /// Converts a file type as returned by the file system to a FUSE file type.
@@ -313,6 +313,10 @@ mod tests {
         // modified and may not be queryable, so stub them out.
         attr.ctime = BAD_TIME;
         attr.crtime = BAD_TIME;
+        // Ignore rdev too
+        attr.rdev = 0;
+        // XXX: gid is always 0 when the tests run on tmpfs(5)
+        attr.gid = exp_attr.gid;
         assert!(fileattrs_eq(&exp_attr, &attr));
     }
 
@@ -350,6 +354,10 @@ mod tests {
         // modified and may not be queryable, so stub them out.
         attr.ctime = BAD_TIME;
         attr.crtime = BAD_TIME;
+        // Ignore rdev too
+        attr.rdev = 0;
+        // XXX: gid is always 0 when the tests run on tmpfs(5)
+        attr.gid = exp_attr.gid;
         assert!(fileattrs_eq(&exp_attr, &attr));
     }
 
