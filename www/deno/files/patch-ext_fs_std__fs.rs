--- ext/fs/std_fs.rs.orig	2023-04-17 15:27:55 UTC
+++ ext/fs/std_fs.rs
@@ -70,7 +70,7 @@ impl FileSystem for StdFs {
     {
       Ok(r.bits())
     }
-    #[cfg(target_os = "macos")]
+    #[cfg(any(target_os = "freebsd", target_os = "macos"))]
     {
       Ok(r.bits() as u32)
     }
