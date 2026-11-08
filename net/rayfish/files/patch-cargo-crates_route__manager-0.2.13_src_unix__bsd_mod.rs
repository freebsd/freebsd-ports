--- cargo-crates/route_manager-0.2.13/src/unix_bsd/mod.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/route_manager-0.2.13/src/unix_bsd/mod.rs
@@ -627,7 +627,7 @@ impl From<Ipv4Addr> for sockaddr_in {
             sin_addr: in_addr {
                 s_addr: u32::from_ne_bytes(ip.octets()),
             },
-            sin_zero: [0i8; 8],
+            sin_zero: [0; 8],
         }
     }
 }
