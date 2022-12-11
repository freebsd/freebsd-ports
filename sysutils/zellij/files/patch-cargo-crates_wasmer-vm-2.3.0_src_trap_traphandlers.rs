--- cargo-crates/wasmer-vm-2.3.0/src/trap/traphandlers.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/wasmer-vm-2.3.0/src/trap/traphandlers.rs
@@ -271,7 +271,7 @@ cfg_if::cfg_if! {
                 ))] {
                     pc = context.uc_mcontext.gregs[libc::REG_EIP as usize] as usize;
                     sp = context.uc_mcontext.gregs[libc::REG_ESP as usize] as usize;
-                } else if #[cfg(all(target_os = "freebsd", target_arch = "x86"))] {
+                } else if #[cfg(all(target_os = "freebsd", any(target_arch = "x86", target_arch = "x86_64")))] {
                     pc = context.uc_mcontext.mc_rip as usize;
                     sp = context.uc_mcontext.mc_rsp as usize;
                 } else if #[cfg(all(target_vendor = "apple", target_arch = "x86_64"))] {
