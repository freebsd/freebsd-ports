--- src/library/file_ops.rs.orig	2026-03-14 18:36:17 UTC
+++ src/library/file_ops.rs
@@ -142,7 +142,7 @@ impl Copy {
             #[cfg(target_os = "macos")]
             nix::sys::stat::mknod(dst, kind, dst_mode, dev as i32)?;
             #[cfg(target_os = "freebsd")]
-            nix::sys::stat::mknod(dst, kind, dst_mode, dev as u32)?;
+            nix::sys::stat::mknod(dst, kind, dst_mode, dev as u64)?;
         } else if is_fifo {
             // create new fifo
             nix::unistd::mkfifo(dst, dst_mode)?;
