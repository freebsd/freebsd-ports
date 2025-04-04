--- ext/os/sys_info.rs.orig	2025-04-03 11:12:07 UTC
+++ ext/os/sys_info.rs
@@ -2,6 +2,9 @@ use std::sync::Once;
 #[cfg(target_family = "windows")]
 use std::sync::Once;
 
+#[cfg(target_os = "freebsd")]
+use libc;
+
 type LoadAvg = (f64, f64, f64);
 const DEFAULT_LOADAVG: LoadAvg = (0.0, 0.0, 0.0);
 
@@ -193,6 +196,26 @@ pub fn hostname() -> String {
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
 #[derive(serde::Serialize)]
 #[serde(rename_all = "camelCase")]
 pub struct MemInfo {
@@ -243,6 +266,44 @@ pub fn mem_info() -> Option<MemInfo> {
       }
     }
   }
+
+  #[cfg(target_os = "freebsd")]
+  {
+    let mut v_page_count = 0;
+    let mut v_free_count = 0;
+    let mut v_inactive_count = 0;
+    let mut v_laundry_count = 0;
+
+    if sysctlbyname(b"vm.stats.vm.v_page_count\0", &mut v_page_count) == false {
+      v_page_count = 0;
+    }
+
+    if sysctlbyname(b"vm.stats.vm.v_free_count\0", &mut v_free_count) == false {
+      v_free_count = 0;
+    }
+
+    if sysctlbyname(b"vm.stats.vm.v_inactive_count\0", &mut v_inactive_count) == false {
+      v_inactive_count = 0;
+    }
+
+    if sysctlbyname(b"vm.stats.vm.v_laundry_count\0", &mut v_laundry_count) == false {
+      v_laundry_count = 0;
+    }
+
+    // SAFETY: libc call (get system page size)
+    let pagesize = unsafe { libc::sysconf(libc::_SC_PAGESIZE) } as u64;
+
+    let mem_inactive = v_inactive_count * pagesize;
+    let mem_laundry = v_laundry_count * pagesize;
+
+    mem_info.total = v_page_count * pagesize;
+    mem_info.free = v_free_count * pagesize;
+    mem_info.available = mem_inactive + mem_laundry + mem_info.free;
+
+//    mem_info.swap_total = sys.total_swap();
+//    mem_info.swap_free = sys.free_swap();
+  }
+
   #[cfg(target_vendor = "apple")]
   {
     let mut mib: [i32; 2] = [0, 0];
