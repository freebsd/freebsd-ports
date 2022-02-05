--- src/fsutil.rs.orig	2022-02-01 02:38:43 UTC
+++ src/fsutil.rs
@@ -75,6 +75,8 @@ impl FileLock {
             l_start: 0,
             l_len: 0,
             l_pid: 0,
+            #[cfg(target_os = "freebsd")]
+            l_sysid: 0,
         };
 
         let ctx = FileLockCtx::new(ctx_tag);
@@ -98,6 +100,8 @@ impl FileLock {
             l_start: 0,
             l_len: 0,
             l_pid: 0,
+            #[cfg(target_os = "freebsd")]
+            l_sysid: 0,
         };
 
         let ctx = FileLockCtx::new(ctx_tag);
@@ -123,6 +127,8 @@ impl FileLock {
             l_start: 0,
             l_len: 0,
             l_pid: 0,
+            #[cfg(target_os = "freebsd")]
+            l_sysid: 0,
         };
 
         let ctx = FileLockCtx::new(ctx_tag);
@@ -365,6 +371,22 @@ cfg_if::cfg_if! {
 
         pub fn dev_minor(dev :u64) -> u64 {
             (dev & 0xff) | ((dev & 0xffff0000) >> 8)
+        }
+
+     } else if #[cfg(target_os = "freebsd")] {
+
+        // See https://github.com/freebsd/freebsd-src/sys/sys/types.h
+        pub fn makedev(major: u64, minor: u64) -> libc::dev_t {
+            (((major & 0xffffff00) << 32) | ((major & 0xff) << 8) |
+             ((minor & 0xff00) << 24) | (minor & 0xffff00ff)) as libc::dev_t
+        }
+
+        pub fn dev_major(dev: u64) -> u64 {
+            ((dev >> 32) & 0xffffff00) | ((dev >> 8) & 0xff)
+        }
+
+        pub fn dev_minor(dev :u64) -> u64 {
+            ((dev >> 24) & 0xff00) | (dev & 0xffff00ff)
         }
 
     } else {
