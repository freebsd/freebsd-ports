--- src/fs/xattr.rs.orig	2023-05-25 21:01:19 UTC
+++ src/fs/xattr.rs
@@ -22,17 +22,18 @@ unsafe fn has_xattrs(path: &Path) -> bool {
 /// Checks to see if a directory entry referred to by `path` has extended attributes. If the file
 /// at the provided `path` is symlink the file it points to is interrogated.
 unsafe fn has_xattrs(path: &Path) -> bool {
-    use libc::{c_char, listxattr};
-
-    let path_ptr = {
-        let slice = path.as_os_str().as_bytes();
-        let slice_ptr = slice.as_ptr();
-        slice_ptr.cast::<c_char>()
-    };
-
-    #[cfg(not(target_os = "macos"))]
-    return 0 < listxattr(path_ptr, ptr::null_mut::<c_char>(), 0);
-
-    #[cfg(target_os = "macos")]
-    return 0 < listxattr(path_ptr, ptr::null_mut::<c_char>(), 0, 0);
+//    use libc::{c_char, listxattr};
+//
+//    let path_ptr = {
+//        let slice = path.as_os_str().as_bytes();
+//        let slice_ptr = slice.as_ptr();
+//        slice_ptr.cast::<c_char>()
+//    };
+//
+//    #[cfg(not(target_os = "macos"))]
+//    return 0 < listxattr(path_ptr, ptr::null_mut::<c_char>(), 0);
+//
+//    #[cfg(target_os = "macos")]
+//    return 0 < listxattr(path_ptr, ptr::null_mut::<c_char>(), 0, 0);
+    return false;
 }
