Implement os.cpus() on FreeBSD with sysctl(3) (hw.model, hw.clockrate,
kern.cp_times), matching libuv.

--- ext/node/ops/os/cpus.rs.orig	2026-09-16 15:45:55 UTC
+++ ext/node/ops/os/cpus.rs
@@ -364,6 +364,85 @@ pub fn cpu_info() -> Option<Vec<CpuInfo>> {
   }
 }
 
+#[cfg(target_os = "freebsd")]
+pub fn cpu_info() -> Option<Vec<CpuInfo>> {
+  use std::ffi::CStr;
+  use std::mem::size_of;
+
+  // Reads a sysctl into `buf`, returning the number of bytes written.
+  fn sysctl_read<T>(name: &CStr, buf: &mut [T]) -> Option<usize> {
+    let mut size = std::mem::size_of_val(buf) as libc::size_t;
+    // SAFETY: `name` is NUL-terminated and `buf` is valid for `size` bytes.
+    let res = unsafe {
+      libc::sysctlbyname(
+        name.as_ptr(),
+        buf.as_mut_ptr() as *mut libc::c_void,
+        &mut size,
+        std::ptr::null_mut(),
+        0,
+      )
+    };
+    (res == 0).then_some(size)
+  }
+
+  let mut ncpu = [0 as libc::c_int];
+  sysctl_read(c"hw.ncpu", &mut ncpu)?;
+  let ncpu = usize::try_from(ncpu[0]).ok()?;
+
+  let mut model = [0u8; 512];
+  let model_len = sysctl_read(c"hw.model", &mut model)?;
+  let model = CStr::from_bytes_until_nul(&model[..model_len])
+    .ok()?
+    .to_string_lossy()
+    .into_owned();
+
+  // Not every platform provides these; report 0 as libuv does when unknown.
+  let mut speed = [0 as libc::c_int];
+  if sysctl_read(c"hw.clockrate", &mut speed).is_none() {
+    let _ = sysctl_read(c"dev.cpu.0.freq", &mut speed);
+  }
+  let speed = u64::try_from(speed[0]).unwrap_or(0);
+
+  // kern.cp_times is sized for every possible CPU id, which may exceed
+  // hw.ncpu, so size the buffer for kern.smp.maxcpus.
+  let mut maxcpus = [0 as libc::c_int];
+  let maxcpus = match sysctl_read(c"kern.smp.maxcpus", &mut maxcpus) {
+    Some(_) => usize::try_from(maxcpus[0]).ok()?.max(ncpu),
+    None => ncpu,
+  };
+  let cpustates = libc::CPUSTATES as usize;
+  let mut cp_times = vec![0 as libc::c_long; maxcpus * cpustates];
+  let len = sysctl_read(c"kern.cp_times", &mut cp_times)?;
+  let ncpu = ncpu.min(len / (cpustates * size_of::<libc::c_long>()));
+
+  // SAFETY: sysconf is always safe to call for _SC_CLK_TCK.
+  let ticks = u64::try_from(unsafe { libc::sysconf(libc::_SC_CLK_TCK) })
+    .ok()
+    .filter(|t| *t > 0)?;
+  // Convert clock ticks to milliseconds
+  let to_ms = |state: libc::c_int, times: &[libc::c_long]| {
+    (times[state as usize] as u64).saturating_mul(1000) / ticks
+  };
+
+  let cpus = cp_times
+    .chunks_exact(cpustates)
+    .take(ncpu)
+    .map(|times| CpuInfo {
+      model: model.clone(),
+      speed,
+      times: CpuTimes {
+        user: to_ms(libc::CP_USER, times),
+        nice: to_ms(libc::CP_NICE, times),
+        sys: to_ms(libc::CP_SYS, times),
+        idle: to_ms(libc::CP_IDLE, times),
+        irq: to_ms(libc::CP_INTR, times),
+      },
+    })
+    .collect();
+
+  Some(cpus)
+}
+
 #[cfg(test)]
 mod tests {
   use super::*;
