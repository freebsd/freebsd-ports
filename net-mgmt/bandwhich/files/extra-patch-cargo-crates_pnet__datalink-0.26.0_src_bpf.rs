--- cargo-crates/pnet_datalink-0.26.0/src/bpf.rs.orig	2020-10-11 18:58:25 UTC
+++ cargo-crates/pnet_datalink-0.26.0/src/bpf.rs
@@ -130,7 +130,7 @@ pub fn channel(network_interface: &NetworkInterface, c
     }
     let mut iface: bpf::ifreq = unsafe { mem::zeroed() };
     for (i, c) in network_interface.name.bytes().enumerate() {
-        iface.ifr_name[i] = c as i8;
+        iface.ifr_name[i] = c as u8;
     }
 
     let buflen = config.read_buffer_size as libc::c_uint;
