--- cargo-crates/deno_panic-0.1.0/src/libunwind.rs.orig	2025-04-07 10:22:01 UTC
+++ cargo-crates/deno_panic-0.1.0/src/libunwind.rs
@@ -40,7 +40,7 @@ unsafe fn dyn_slide(addr: u64) -> usize {
     addr as usize - (_dyld_get_image_vmaddr_slide(0) + (&*cmd).vmaddr as usize)
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 unsafe fn dyn_slide(addr: u64) -> u64 {
     use std::ffi::{c_int, c_void};
 
@@ -65,7 +65,7 @@ unsafe fn dyn_slide(addr: u64) -> u64 {
         let mut current = unsafe { (*info).dlpi_phdr };
         let end = current.add(unsafe { (*info).dlpi_phnum } as usize);
         while current < end {
-            if unsafe { (*current).p_type != libc::PT_LOAD } {
+            if unsafe { (*current).p_type != 1 } {
                 current = current.add(1);
                 continue;
             }
