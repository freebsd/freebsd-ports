--- cargo-crates/libsui-0.16.4/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/libsui-0.16.4/lib.rs
@@ -1509,8 +1509,9 @@ mod elf {
 
 #[cfg(all(unix, not(target_vendor = "apple")))]
 mod elf {
-    use libc::{dl_iterate_phdr, dl_phdr_info, Elf64_Phdr, PT_NOTE};
+    use libc::{dl_iterate_phdr, dl_phdr_info, Elf64_Phdr};
     use std::os::raw::{c_int, c_void};
+    const PT_NOTE: u32 = 4;
 
     unsafe extern "C" fn sui_dl_iterate_phdr_callback(
         info: *mut dl_phdr_info,
