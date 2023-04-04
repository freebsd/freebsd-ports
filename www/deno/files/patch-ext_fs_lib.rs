--- ext/fs/lib.rs.orig	2023-04-04 15:26:01 UTC
+++ ext/fs/lib.rs
@@ -633,7 +633,7 @@ fn op_umask(state: &mut OpState, mask: Option<u32>) ->
     {
       Ok(r.bits())
     }
-    #[cfg(target_os = "macos")]
+    #[cfg(any(target_os = "freebsd", target_os = "macos"))]
     {
       Ok(r.bits() as u32)
     }
