--- runtime/ops/fs.rs.orig	2023-01-13 13:11:57.362303000 +0100
+++ runtime/ops/fs.rs	2023-01-13 13:45:44.047446000 +0100
@@ -529,7 +529,7 @@ fn op_umask(state: &mut OpState, mask: Option<u32>) ->
     {
       Ok(r.bits())
     }
-    #[cfg(target_os = "macos")]
+    #[cfg(any(target_os = "freebsd", target_os = "macos"))]
     {
       Ok(r.bits() as u32)
     }
