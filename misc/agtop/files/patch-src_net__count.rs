--- src/net_count.rs.orig	2026-10-27 13:12:25 UTC
+++ src/net_count.rs
@@ -184,7 +184,6 @@
 
     #[repr(C)]
     struct FileStat {
-        next:        *mut c_void,
         fs_type:     c_int,
         fs_flags:    c_int,
         fs_fflags:   c_int,
@@ -259,7 +258,7 @@
             let f = &mut *node;
             if f.fs_type == PS_FST_TYPE_SOCKET {
                 let mut ss = SockStat::default();
-                let mut errbuf = [0i8; 256];
+                let mut errbuf = [0 as c_char; 256];
                 let rc = procstat_get_socket_info(ps, node, &mut ss, errbuf.as_mut_ptr());
                 if rc == 0 {
                     // sockstat layout (FreeBSD 12+ typical):
