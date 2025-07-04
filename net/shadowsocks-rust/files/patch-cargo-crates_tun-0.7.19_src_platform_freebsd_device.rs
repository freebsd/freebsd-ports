--- cargo-crates/tun-0.7.19/src/platform/freebsd/device.rs.orig	2025-07-04 17:40:17 UTC
+++ cargo-crates/tun-0.7.19/src/platform/freebsd/device.rs
@@ -296,10 +296,10 @@ impl AbstractDevice for Device {
             }
             let mut req = self.request();
             let tun_name = CString::new(value)?;
-            let mut tun_name: Vec<i8> = tun_name
+            let mut tun_name: Vec<c_char> = tun_name
                 .into_bytes_with_nul()
                 .into_iter()
-                .map(|c| c as i8)
+                .map(|c| c as c_char)
                 .collect::<_>();
             req.ifr_ifru.ifru_data = tun_name.as_mut_ptr();
             if let Err(err) = siocsifname(self.ctl.as_raw_fd(), &req) {
