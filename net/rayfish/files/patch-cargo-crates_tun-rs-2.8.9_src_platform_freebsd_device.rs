--- cargo-crates/tun-rs-2.8.9/src/platform/freebsd/device.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tun-rs-2.8.9/src/platform/freebsd/device.rs
@@ -11,7 +11,7 @@ use crate::{
 use crate::platform::unix::device::{copy_device_name, ctl, ctl_v6};
 use libc::{
     self, c_char, c_short, fcntl, ifreq, kinfo_file, AF_LINK, F_KINFO, IFF_RUNNING, IFF_UP,
-    IFNAMSIZ, KINFO_FILE_SIZE, O_RDWR,
+    IFNAMSIZ, O_RDWR,
 };
 use std::io::ErrorKind;
 use std::os::fd::{IntoRawFd, RawFd};
@@ -288,7 +288,7 @@ impl DeviceImpl {
         use std::path::PathBuf;
         unsafe {
             let mut path_info: kinfo_file = std::mem::zeroed();
-            path_info.kf_structsize = KINFO_FILE_SIZE;
+            path_info.kf_structsize = std::mem::size_of::<kinfo_file>() as libc::c_int;
             if fcntl(tun.as_raw_fd(), F_KINFO, &mut path_info as *mut _) < 0 {
                 return Err(io::Error::last_os_error());
             }
