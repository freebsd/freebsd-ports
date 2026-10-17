--- src/net_count.rs.orig
+++ src/net_count.rs
@@ -259,7 +259,7 @@
             let f = &mut *node;
             if f.fs_type == PS_FST_TYPE_SOCKET {
                 let mut ss = SockStat::default();
-                let mut errbuf = [0i8; 256];
+                let mut errbuf = [0 as c_char; 256];
                 let rc = procstat_get_socket_info(ps, node, &mut ss, errbuf.as_mut_ptr());
                 if rc == 0 {
                     // sockstat layout (FreeBSD 12+ typical):
