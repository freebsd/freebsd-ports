--- cargo-crates/pcap-sys-0.1.3/build.rs.orig	2022-03-31 13:14:17 UTC
+++ cargo-crates/pcap-sys-0.1.3/build.rs
@@ -35,6 +35,7 @@ fn main() {
 
     // on macOS, pcap-config returns /usr/local/lib, but libpcap is actually in /usr/lib
     println!("cargo:rustc-link-search=native=/usr/lib");
+    println!("cargo:rustc-link-lib=pcap");
 }
 
 /// Adapted from pkg_config
