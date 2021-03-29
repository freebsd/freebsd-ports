--- lib/std/os/bits/freebsd.zig.orig	2020-12-13 19:14:58 UTC
+++ lib/std/os/bits/freebsd.zig
@@ -15,6 +15,7 @@ pub const gid_t = u32;
 pub const mode_t = c_uint;
 
 pub const socklen_t = u32;
+pub const suseconds_t = c_long;
 
 /// Renamed from `kevent` to `Kevent` to avoid conflict with function name.
 pub const Kevent = extern struct {
@@ -159,6 +160,13 @@ pub const libc_stat = extern struct {
 pub const timespec = extern struct {
     tv_sec: isize,
     tv_nsec: isize,
+};
+
+pub const timeval = extern struct {
+    /// seconds
+    tv_sec: time_t,
+    /// microseconds
+    tv_usec: suseconds_t,
 };
 
 pub const dirent = extern struct {
