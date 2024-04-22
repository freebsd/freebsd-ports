--- ext/node/ops/fs.rs.orig	2024-03-17 20:31:23 UTC
+++ ext/node/ops/fs.rs
@@ -120,13 +120,13 @@ where
     let mut cpath = path.as_bytes().to_vec();
     cpath.push(0);
     if bigint {
-      #[cfg(not(target_os = "macos"))]
+      #[cfg(not(any(target_os = "freebsd", target_os = "macos")))]
       // SAFETY: `cpath` is NUL-terminated and result is pointer to valid statfs memory.
       let (code, result) = unsafe {
         let mut result: libc::statfs64 = std::mem::zeroed();
         (libc::statfs64(cpath.as_ptr() as _, &mut result), result)
       };
-      #[cfg(target_os = "macos")]
+      #[cfg(any(target_os = "freebsd", target_os = "macos"))]
       // SAFETY: `cpath` is NUL-terminated and result is pointer to valid statfs memory.
       let (code, result) = unsafe {
         let mut result: libc::statfs = std::mem::zeroed();
