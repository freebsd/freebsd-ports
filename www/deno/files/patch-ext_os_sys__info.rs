--- ext/os/sys_info.rs.orig	2026-07-01 13:28:43 UTC
+++ ext/os/sys_info.rs
@@ -192,6 +192,26 @@ pub fn hostname() -> String {
   }
 }
 
+#[cfg(target_os = "freebsd")]
+pub fn sysctlbyname<T: Sized>(name: &[u8], oldp: &mut T) -> bool {
+  let mut oldlenp = std::mem::size_of::<T>() as libc::size_t;
+
+  unsafe {
+    let res = libc::sysctlbyname(
+      name.as_ptr() as *const libc::c_char,
+      oldp as *mut _ as *mut _,
+      &mut oldlenp,
+      std::ptr::null_mut(),
+      0,
+    );
+    if res != 0 {
+        return false;
+    } else {
+        return true;
+    }
+  }
+}
+
 #[derive(ToV8)]
 pub struct MemInfo {
   pub total: u64,
@@ -240,6 +260,35 @@ pub fn mem_info() -> Option<MemInfo> {
         mem_info.available = mem.unwrap_or(0) * 1024;
       }
     }
+  }
+  #[cfg(target_os = "freebsd")]
+  {
+    let mut v_page_count: u32 = 0;
+    let mut v_free_count: u32 = 0;
+    let mut v_inactive_count: u32 = 0;
+    let mut v_laundry_count: u32 = 0;
+
+    if !sysctlbyname(b"vm.stats.vm.v_page_count\0", &mut v_page_count) {
+      v_page_count = 0;
+    }
+    if !sysctlbyname(b"vm.stats.vm.v_free_count\0", &mut v_free_count) {
+      v_free_count = 0;
+    }
+    if !sysctlbyname(b"vm.stats.vm.v_inactive_count\0", &mut v_inactive_count) {
+      v_inactive_count = 0;
+    }
+    if !sysctlbyname(b"vm.stats.vm.v_laundry_count\0", &mut v_laundry_count) {
+      v_laundry_count = 0;
+    }
+
+    // SAFETY: sysconf is always safe to call for _SC_PAGESIZE.
+    let pagesize = unsafe { libc::sysconf(libc::_SC_PAGESIZE) } as u64;
+
+    mem_info.total = v_page_count as u64 * pagesize;
+    mem_info.free = v_free_count as u64 * pagesize;
+    mem_info.available =
+      (v_free_count as u64 + v_inactive_count as u64 + v_laundry_count as u64)
+        * pagesize;
   }
   #[cfg(target_vendor = "apple")]
   {
