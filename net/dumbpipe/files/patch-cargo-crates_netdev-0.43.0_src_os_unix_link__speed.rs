--- cargo-crates/netdev-0.43.0/src/os/unix/link_speed.rs.orig	2026-06-12 13:12:37 UTC
+++ cargo-crates/netdev-0.43.0/src/os/unix/link_speed.rs
@@ -105,7 +105,7 @@ const SIOCGIFXMEDIA: u64 = 0xc02c6948;
 // #define SIOCGIFMEDIA    _IOWR('i', 56, struct ifmediareq)
 // const SIOCGIFMEDIA: u64 = 0xc02c6938;
 
-#[cfg(all(target_os = "freebsd", target_arch = "x86_64"))]
+#[cfg(all(target_os = "freebsd", target_pointer_width = "64"))]
 // https://github.com/freebsd/freebsd-src/blob/master/sys/sys/sockio.h#L139
 // #define	SIOCGIFXMEDIA	_IOWR('i', 139, struct ifmediareq)
 const SIOCGIFXMEDIA: u64 = 0xc030698b;
