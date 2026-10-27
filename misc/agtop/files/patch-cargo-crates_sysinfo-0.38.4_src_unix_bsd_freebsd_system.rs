--- cargo-crates/sysinfo-0.38.4/src/unix/bsd/freebsd/system.rs.orig	2026-10-27 13:12:25 UTC
+++ cargo-crates/sysinfo-0.38.4/src/unix/bsd/freebsd/system.rs
@@ -567,10 +567,10 @@
     }
 
     fn get_total_memory(&self) -> u64 {
-        let mut nb_pages: u64 = 0;
+        let mut nb_pages: u32 = 0;
         unsafe {
             if get_sys_value(&self.virtual_page_count, &mut nb_pages) {
-                return nb_pages.saturating_mul(self.page_size as _);
+                return u64::from(nb_pages).saturating_mul(self.page_size as _);
             }
 
             // This is a fallback. It includes all the available memory, not just the one available
@@ -582,20 +582,20 @@
     }
 
     fn get_used_memory(&self) -> u64 {
-        let mut mem_active: u64 = 0;
-        let mut mem_wire: u64 = 0;
+        let mut mem_active: u32 = 0;
+        let mut mem_wire: u32 = 0;
 
         unsafe {
             get_sys_value(&self.virtual_active_count, &mut mem_active);
             get_sys_value(&self.virtual_wire_count, &mut mem_wire);
 
-            let mut mem_wire = mem_wire.saturating_mul(self.page_size as _);
+            let mut mem_wire = u64::from(mem_wire).saturating_mul(self.page_size as _);
             // We need to subtract "ZFS ARC" from the "wired memory" because it should belongs to cache
             // but the kernel reports it as "wired memory" instead...
             if let Some(arc_size) = self.zfs.arc_size() {
                 mem_wire = mem_wire.saturating_sub(arc_size);
             }
-            mem_active
+            u64::from(mem_active)
                 .saturating_mul(self.page_size as _)
                 .saturating_add(mem_wire)
         }
@@ -603,9 +603,9 @@
 
     fn get_free_memory(&self) -> u64 {
         let mut buffers_mem: u64 = 0;
-        let mut inactive_mem: u64 = 0;
-        let mut cached_mem: u64 = 0;
-        let mut free_mem: u64 = 0;
+        let mut inactive_mem: u32 = 0;
+        let mut cached_mem: u32 = 0;
+        let mut free_mem: u32 = 0;
 
         unsafe {
             get_sys_value(&self.buf_space, &mut buffers_mem);
@@ -614,9 +614,9 @@
             get_sys_value(&self.virtual_free_count, &mut free_mem);
             // For whatever reason, buffers_mem is already the right value...
             buffers_mem
-                .saturating_add(inactive_mem.saturating_mul(self.page_size as _))
-                .saturating_add(cached_mem.saturating_mul(self.page_size as _))
-                .saturating_add(free_mem.saturating_mul(self.page_size as _))
+                .saturating_add(u64::from(inactive_mem).saturating_mul(self.page_size as _))
+                .saturating_add(u64::from(cached_mem).saturating_mul(self.page_size as _))
+                .saturating_add(u64::from(free_mem).saturating_mul(self.page_size as _))
         }
     }
 
