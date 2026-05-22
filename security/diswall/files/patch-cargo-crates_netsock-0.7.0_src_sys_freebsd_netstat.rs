--- cargo-crates/netsock-0.7.0/src/sys/freebsd/netstat.rs.orig
+++ cargo-crates/netsock-0.7.0/src/sys/freebsd/netstat.rs
@@ -103,7 +103,7 @@
 
                 if fst.fs_type == PS_FST_TYPE_SOCKET {
                     let mut sockstat: sockstat = mem::zeroed();
-                    let mut errbuf = [0i8; 256];
+                    let mut errbuf = [0 as std::os::raw::c_char; 256];
 
                     let ret = procstat_get_socket_info(
                         ps,
