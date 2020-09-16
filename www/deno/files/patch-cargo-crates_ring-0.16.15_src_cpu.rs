--- cargo-crates/ring-0.16.15/src/cpu.rs.orig	2020-06-10 22:45:54 UTC
+++ cargo-crates/ring-0.16.15/src/cpu.rs
@@ -60,6 +60,11 @@ pub(crate) fn features() -> Features {
             {
                 arm::fuchsia_setup();
             }
+
+            #[cfg(all(target_os = "freebsd", any(target_arch = "aarch64", target_arch = "arm")))]
+            {
+                arm::freebsd_setup();
+            }
         });
     }
 
@@ -168,6 +173,83 @@ pub(crate) mod arm {
         }
     }
 
+    #[cfg(all(target_os = "freebsd", any(target_arch = "aarch64", target_arch = "arm")))]
+    pub fn freebsd_setup() {
+        extern crate std;
+        use libc::{c_int, c_ulong, c_void};
+
+        extern "C" {
+            fn elf_aux_info(aux: c_int, buf: *mut c_void, buflen: c_int) -> c_int;
+        }
+
+        const AT_HWCAP: c_int = 25;
+
+        #[cfg(target_arch = "aarch64")]
+        const HWCAP_NEON: c_ulong = 1 << 1;
+
+        #[cfg(target_arch = "arm")]
+        const HWCAP_NEON: c_ulong = 1 << 12;
+
+        let caps: c_ulong = 0;
+        let buffer : *mut c_void = { let t: *const c_ulong = &caps; t} as *mut c_void;
+
+        unsafe {
+            let _ret = elf_aux_info(
+                AT_HWCAP,
+                buffer,
+                std::mem::size_of_val(&caps) as i32
+            );
+        }
+
+        // We assume NEON is available on AARCH64 because it is a required
+        // feature.
+        #[cfg(target_arch = "aarch64")]
+        debug_assert!(caps & HWCAP_NEON == HWCAP_NEON);
+
+        // OpenSSL and BoringSSL don't enable any other features if NEON isn't
+        // available.
+        if caps & HWCAP_NEON == HWCAP_NEON {
+            let mut features = NEON.mask;
+
+            #[cfg(target_arch = "aarch64")]
+            const OFFSET: c_ulong = 3;
+
+            #[cfg(target_arch = "arm")]
+            const OFFSET: c_ulong = 0;
+            #[cfg(target_arch = "arm")]
+            const AT_HWCAP2: c_int = 26;
+            #[cfg(target_arch = "arm")]
+            let caps: c_ulong = 0;
+            #[cfg(target_arch = "arm")]
+            let buffer : *mut c_void = { let t: *const c_ulong = &caps; t} as *mut c_void;
+
+            #[cfg(target_arch = "arm")]
+            unsafe {
+                let _ret = elf_aux_info(
+                    AT_HWCAP2,
+                    buffer,
+                    std::mem::size_of_val(&caps) as i32
+                );
+            };
+
+            const HWCAP_AES: c_ulong = 1 << 0 + OFFSET;
+            const HWCAP_PMULL: c_ulong = 1 << 1 + OFFSET;
+            const HWCAP_SHA2: c_ulong = 1 << 3 + OFFSET;
+
+            if caps & HWCAP_AES == HWCAP_AES {
+                features |= AES.mask;
+            }
+            if caps & HWCAP_PMULL == HWCAP_PMULL {
+                features |= PMULL.mask;
+            }
+            if caps & HWCAP_SHA2 == HWCAP_SHA2 {
+                features |= 1 << 4;
+            }
+
+            unsafe { GFp_armcap_P = features };
+        }
+    }
+
     #[cfg(not(target_arch = "wasm32"))]
     pub(crate) struct Feature {
         #[cfg_attr(
@@ -193,7 +275,7 @@ pub(crate) mod arm {
             }
 
             #[cfg(all(
-                any(target_os = "android", target_os = "linux", target_os = "fuchsia"),
+                any(target_os = "android", target_os = "linux", target_os = "fuchsia", target_os = "freebsd"),
                 any(target_arch = "arm", target_arch = "aarch64")
             ))]
             {
@@ -239,7 +321,7 @@ pub(crate) mod arm {
     };
 
     #[cfg(all(
-        any(target_os = "android", target_os = "linux", target_os = "fuchsia"),
+        any(target_os = "android", target_os = "linux", target_os = "fuchsia", target_os = "freebsd"),
         any(target_arch = "arm", target_arch = "aarch64")
     ))]
     extern "C" {
