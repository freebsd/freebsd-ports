--- runtime/ops/os/sys_info.rs.orig	2022-11-13 21:31:36 UTC
+++ runtime/ops/os/sys_info.rs
@@ -296,6 +296,20 @@ pub fn mem_info() -> Option<MemInfo> {
         mem_info.swap_free = mem_info.swap_total;
       }
     }
+  }
+  #[cfg(target_os = "freebsd")]
+  {
+    use sysinfo::System;
+    let mut sys = System::new_all();
+
+    // First we update all information of our `System` struct.
+    sys.refresh_all();
+
+    mem_info.swap_total = sys.total_swap();
+    mem_info.swap_free = sys.free_swap();
+    mem_info.total = sys.total_memory();
+    mem_info.free = sys.free_memory();
+    mem_info.available = sys.available_memory();
   }
 
   Some(mem_info)
