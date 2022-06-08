--- cargo-crates/pnet_datalink-0.28.0/src/bpf.rs.orig	2022-06-08 16:54:23 UTC
+++ cargo-crates/pnet_datalink-0.28.0/src/bpf.rs
@@ -130,7 +130,7 @@ pub fn channel(network_interface: &NetworkInterface, c
     }
     let mut iface: bpf::ifreq = unsafe { mem::zeroed() };
     for (i, c) in network_interface.name.bytes().enumerate() {
-        iface.ifr_name[i] = c as i8;
+        iface.ifr_name[i] = c as libc::c_char;
     }
 
     let buflen = config.read_buffer_size as libc::c_uint;
