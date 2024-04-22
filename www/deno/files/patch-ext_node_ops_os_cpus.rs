XXX need to retrieve cpu_times correctly

--- ext/node/ops/os/cpus.rs.orig	2024-03-17 20:42:18 UTC
+++ ext/node/ops/os/cpus.rs
@@ -293,6 +293,33 @@ pub fn cpu_info() -> Option<Vec<CpuInfo>> {
   Some(cpus)
 }
 
+#[cfg(target_os = "freebsd")]
+pub fn cpu_info() -> Option<Vec<CpuInfo>> {
+  use sysinfo::System;
+
+  let sys = System::new_all();
+
+  let mut cpu_speed: u64 = 0;
+  cpu_speed = sys.cpus()[0].frequency();
+
+  let mut num_cpus: usize = 0;
+  num_cpus = sys.physical_core_count().unwrap();
+
+  let mut allcpus = vec![CpuInfo::new(); num_cpus as usize];
+
+  for i in 0..num_cpus {
+    allcpus[i].model = sys.cpus()[i].vendor_id().to_string();
+    allcpus[i].times.user = 0;
+    allcpus[i].times.nice = 0;
+    allcpus[i].times.sys = 0;
+    allcpus[i].times.idle = 0;
+    allcpus[i].times.irq = 0;
+
+    allcpus[i].speed = cpu_speed;
+  }
+  Some(allcpus)
+}
+
 #[cfg(test)]
 mod tests {
   use super::*;
